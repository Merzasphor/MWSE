return {
	type = "class",
	description = [[A structure that keeps track of information related two the game's two moons.

Moon move in an arc shape along the sky. The arc's start is at in-game North and ends in the South. The arc's plane can be rotated from North-South axis, by `axisOffset` property. If moons overlap, Secunda is always rendered in front of Masser, so the Masser is covered by Secunda.

Each moon has 8 phases, which differ by the amount of the moon that is visible and the part covered in black. During waxing the moon appears in the sky during the first part of the night, before midnight. After the full phase, the moons usually rise during the later part of the night, after midnight. Much like the Earth's moon. Absolutely the first moment the moon can appear is controlled by `fadeInStart` property, while the latest moment the moon sets is controlled by `fadeOutFinish` property.

Most of the properties exposed here correspond to the setting of the same name in [Moons] section of the Morrowind.ini file.]],
}