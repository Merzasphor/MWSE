---
hide:
  - toc
---

# Texture Format Preference Mip Flags

!!! tip
	These values are available in Lua by their index in the `ni.textureFormatPrefsMipFlag` table. For example, `ni.textureFormatPrefsMipFlag.yes` has a value of `1`.

Index   | Value  | Description
------- | ------ | ----------------
no      | `0`    | Texture prefers no mipmapping ("flat" image).
yes     | `1`    | Texture prefers mipmapping.
default | `2`    | Texture can use the default setting from niTexture.
