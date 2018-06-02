using System;
using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Net;
using System.Threading;
using Microsoft.Win32;

namespace MWSE
{
    /// <summary>
    /// The main auto updater program. The program will do the following:
    /// 1) Reads a text file at https://nullcascade.com/mwse/version_dev
    /// 2) Compares its version information to the local mwse-version.txt file.
    /// 3) If the version doesn't match, it downloads the file from https://nullcascade.com/mwse/mwse-dev.zip
    /// 4) Extracts the contents and cleans up after itself.
    /// 5) Saves the new version as mwse-version.txt.
    /// </summary>
    class MWSEAutoUpdater
    {
        /// <summary>
        /// Determines if Morrowind is currently running in the background.
        /// </summary>
        /// <returns>
        /// True if the process could be found, otherwise false.
        /// </returns>
        static bool IsMorrowindRunning()
        {
            foreach (Process process in Process.GetProcesses())
            {
                if (process.ProcessName.Contains("Morrowind"))
                {
                    Console.WriteLine(process.ProcessName);
                    return true;
                }
            }

            return false;
        }

        /// <summary>
        /// Program entry point.
        /// </summary>
        /// <param name="args">
        /// Arguments. Currently none supported.
        /// </param>
        static void Main(string[] args)
        {
            // Check to see if Morrowind is running; wait for it to close.
            if (IsMorrowindRunning())
            {
                Console.WriteLine("Waiting for Morrowind to close...");
                while (IsMorrowindRunning())
                {
                    Thread.Sleep(1000);
                }
            }

            // Try to find Morrowind's install location, store it here.
            String installLocation = null;

            // First we'll check the current directory.
            if (File.Exists("Morrowind.exe"))
            {
                installLocation = AppDomain.CurrentDomain.BaseDirectory;
            }
            // Fall back to the registry.
            else if (String.IsNullOrEmpty(installLocation))
            {
                String registryValue = Registry.GetValue("HKEY_LOCAL_MACHINE\\SOFTWARE\\WOW6432Node\\bethesda softworks\\Morrowind", "Installed Path", null) as String;
                if (!String.IsNullOrEmpty(registryValue) && File.Exists(Path.Combine(registryValue, "Morrowind.exe")))
                {
                    installLocation = registryValue;
                }
            }

            // Make sure that we actually have a valid install location.
            if (!String.IsNullOrEmpty(installLocation))
            {
                Console.WriteLine("Found install location: {0}", installLocation);
            }
            else
            {
                Console.WriteLine("ERROR: Could not determine Morrowind install location. Please place the program in the same folder as Morrowind.exe.");
#if _DEBUG
                Console.ReadKey();
#endif
                return;
            }

            try
            {
                WebClient webClient = new WebClient();

                // Get the currently installed version.
                String currentVersion = null;
                if (File.Exists("mwse-version.txt"))
                {
                    currentVersion = File.ReadAllText("mwse-version.txt").Trim();
                    Console.WriteLine("Installed version: {0}", currentVersion);
                }

                // Check the latest dev version.
                String latestVersion = webClient.DownloadString("https://nullcascade.com/mwse/version_dev").Trim();
                File.Delete("version_dev");
                if (String.IsNullOrEmpty(latestVersion))
                {
                    Console.WriteLine("ERROR: Could not determine version string!");
#if _DEBUG
                Console.ReadKey();
#endif
                    return;
                }
                Console.WriteLine("Newest version: {0}", latestVersion);

                // Do the versions match?
                if (currentVersion == latestVersion)
                {
                    Console.WriteLine("Currently up to date.");
                    return;
                }

                // Download the update.
                Console.Write("Downloading update ...");
                webClient.DownloadFile("https://nullcascade.com/mwse/mwse-dev.zip", "mwse-update.zip");
                Console.WriteLine(" Done.");

                // Extract its contents. We can't just use ZipFile.ExtractToDirectory because it won't overwrite files.
                Console.Write("Extracting update ...");
                using (ZipArchive archive = ZipFile.Open("mwse-update.zip", ZipArchiveMode.Read))
                {
                    foreach (ZipArchiveEntry file in archive.Entries)
                    {
                        if (file.Name == "Updater.exe")
                        {
                            continue;
                        }

                        string completeFileName = Path.Combine(installLocation, file.FullName);
                        if (file.Name == "")
                        {
                            Directory.CreateDirectory(Path.GetDirectoryName(completeFileName));
                            continue;
                        }
                        file.ExtractToFile(completeFileName, true);
                    }
                }
                Console.WriteLine(" Done.");

                // Delete the update zip.
                File.Delete("mwse-update.zip");

                // Write the current version to the version cache file.
                File.WriteAllText("mwse-version.txt", latestVersion);
            }
            catch (Exception e)
            {
                Console.WriteLine("\nThere was a problem when updating MWSE: {0}", e.Message);
#if _DEBUG
                Console.ReadKey();
#endif
            }

#if _DEBUG
            Console.ReadKey();
#endif
        }
    }
}
