---
hide:
  - toc
---

# Pick Intersection Types

!!! tip
	These values are available in Lua by their index in the `ni.pickIntersectType` table. For example, `ni.pickIntersectType.triangleIntersect` has a value of `1`.

Index             | Value  | Description
----------------- | ------ | ----------------
boundIntersect    | `0`    | Intersection calculations are performed on the bounding spheres of objects. In this mode, intersections are either hit or miss, and calculations for the exact intersection point are not performed. Since exact intersection points are not calculated, the `sortType` is ignored.
triangleIntersect | `1`    | Intersection calculations are performed on the triangles that compose the objects. In this mode, intersections are exact. Calculations for the exact intersection point are performed and the intersection point, parametric distance from the ray origin, and index of the intersected triangle are stored in the niPickRecord. Once all intersections are calculated the array is sorted based on the `sortType`. Since only triangles are processed, niPickRecords are only added for the leaf nodes. Note that more than one pick record could be added per leaf node if more than one triangle intersection occurs.
