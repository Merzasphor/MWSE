---
hide:
  - toc
---

# Animation States

!!! tip
	These values are available in Lua by their index in the `tes3.animationState` table. For example, `tes3.animationState.readyingWeap` has a value of `8`.

Index            | Value
---------------- | -----
idle             | `0`
ready            | `1`
swingUp          | `2`
swingDown        | `3`
swingHit         | `4`
swingFollowLight | `5`
swingFollowMed   | `6`
swingFollowHeavy | `7`
readyingWeap     | `8`
unreadyWeap      | `9`
casting          | `10`
casting2         | `11`
readyingMagic    | `12`
unreadyMagic     | `13`
knockdown        | `14`
knockedOut       | `15`
pickingProbing   | `16`
dying            | `18`
dead             | `19`
