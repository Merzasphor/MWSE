---
hide:
  - toc
---

# Magic Effect Flags

!!! tip
	These values are available in Lua with their field access. Instead of manually setting the flags. For example use `.targetsSkills`. See the [Magic Effect type page](../types/tes3magicEffect) for more information.

Value  | Meaning
------ | ----------------
1      | Targets skill.
2      | Targets attribute.
4      | No duration.
8      | No magnitude.
16     | Harmful.
32     | Continuous VFX.
64     | Cast self.
128    | Cast touch.
256    | Cast target.
512    | Valid for spellmaking.
1024   | Valid for enchanting.
2048   | Negative lighting.
4096   | Applied once.
8192   | Stealth.
16384  | Non-recastable.
32768  | Illegal daedra.
65536  | Unreflectable.
131072 | Caster linked.