-- French translation by Daichi
return {
	["notice.label"] = "Note :",
	["notice.text"] = "Ces options peuvent ne pas prendre effet avant le prochain lancement du jeu.",
	["credits.label"] = "Les personnes suivantes ont contribué à Morrowind Script Extender:",
	["logWarningsWithLuaStack.label"] = "Journalisation des avertissements avec une trace d'appels Lua?",
	["logWarningsWithLuaStack.text"] = "Si cette option est activée, tout avertissement déclenché en cours de jeu qui génère une ligne dans Warnings.txt générera également des lignes dans mwse.log. De plus, une trace d'appels sera fournie pour contextualiser quel mod a pu être responsable de l'avertissement généré.\n\nCette fonction peut entraîner la génération d'entrées superflues dans les fichiers log si vous utilisez certains mods (par exemple Better Bodies).",
	["runInBackground.label"] = "Faire tourner Morrowind en arrière-plan?",
	["runInBackground.text"] = "Par défaut, Morrowind suspend l'exécution d'une grande part de son code lorsqu'il n'est pas au premier plan. Lorsque vous utilisez le mode fenêtré (y compris le mode plein écran sans bordures), cette option permet à Morrowind de continuer à tourner. L'activation de cette option peut également améliorer la stabilité du jeu en raison de la façon dont Morrowind gère certains fils d'exécution audio.",
	["patchNiFlipController.label"] = "Corriger le clonage des NiFlipController?",
	["patchNiFlipController.text"] = "Morrowind gère de façon incorrecte le mapping affecté lorsqu'il clone des objets NiFlipController, ce qui empêche les mods d'utiliser ces contrôleurs pour quoi que ce soit d'autre que la base map. MWSE corrige ce problème, mais certains mods contiennent des modèles buggés auxquels est assigné le mapping affecté incorrect et qui dépendent du bug pour réassigner le contrôleur à la base map. Désactiver cette option activera le support de ces mods, mais empêchera des mods plus récents de profiter du contrôleur corrigé.\n\nIl est recommandé de laisser cette option activée à moins que n'ayez la certitude d'avoir besoin d'activer la compatibilité avec des mods concernés.",
	["keepAllNetImmerseObjectsAlive.label"] = "Mettre en cache tous les objets lua NetImmerse?",
	["keepAllNetImmerseObjectsAlive.text"] = "ATTENTION : Utilisé uniquement pour faire du débuggage. Si vous ne savez pas ce que vous faites, activer cette option causera A COUP SUR des fuites de mémoire.\n\nQuand cette option est activée, les objets NetImmerse utiliseront le même système de mise en cache d'objets lua que celui utilisé pour les objets TES3, ce qui permet de les comparer en tant que chaînes de caractères ou de les utiliser comme clés de tableaux.",
	["enableLegacyLuaMods.label"] = "Activer les vieux mods lua?",
	["enableLegacyLuaMods.text"] = "Cette option active le support des mods lua créés au tout début de MWSE 2.1.\n\nCes mods se trouvent dans le dossier suivant :\nData Files\\MWSE\\lua.",
}