function reloadMermaidPagesOnPaletteSwitch() {
	if (document.getElementsByClassName("mermaid").length > 0) {
		location.reload();
	}
}

document.getElementById("__palette_1").addEventListener("change", reloadMermaidPagesOnPaletteSwitch);
document.getElementById("__palette_2").addEventListener("change", reloadMermaidPagesOnPaletteSwitch);
