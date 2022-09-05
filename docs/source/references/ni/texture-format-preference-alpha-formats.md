---
hide:
  - toc
---

# Texture Format Preference Alpha Formats

!!! tip
	These values are available in Lua by their index in the `ni.textureFormatPrefsAlphaFormat` table. For example, `ni.textureFormatPrefsAlphaFormat.smooth` has a value of `2`.

Index   | Value  | Description
------- | ------ | ----------------
none    | `0`    | Texture doesn't use alpha.
binary  | `1`    | Texture needs only 1-bit (on/off) alpha.
smooth  | `2`    | Texture needs multi-level alpha (4 to 8 bits of alpha).
default | `3`    | Texture can use an alpha format that best fits the source data.
