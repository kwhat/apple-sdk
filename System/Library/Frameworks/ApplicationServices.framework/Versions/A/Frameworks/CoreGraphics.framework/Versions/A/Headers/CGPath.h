/* CoreGraphics - CGPath.h
 * Copyright (c) 2001-2008 Apple Inc.
 * All rights reserved. */

#ifndef CGPATH_H_
#define CGPATH_H_

typedef struct CGPath *CGMutablePathRef;
typedef const struct CGPath *CGPathRef;

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGAffineTransform.h>
#include <CoreFoundation/CFBase.h>

/* Return the CFTypeID for CGPathRefs. */

CG_EXTERN CFTypeID CGPathGetTypeID(void)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Create a mutable path. */

CG_EXTERN CGMutablePathRef CGPathCreateMutable(void)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Create a copy of `path'. */

CG_EXTERN CGPathRef CGPathCreateCopy(CGPathRef path)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Create a mutable copy of `path'. */

CG_EXTERN CGMutablePathRef CGPathCreateMutableCopy(CGPathRef path)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Equivalent to `CFRetain(path)', except it doesn't crash (as CFRetain
   does) if `path' is NULL. */

CG_EXTERN CGPathRef CGPathRetain(CGPathRef path)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Equivalent to `CFRelease(path)', except it doesn't crash (as CFRelease
   does) if `path' is NULL. */

CG_EXTERN void CGPathRelease(CGPathRef path)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Return true if `path1' is equal to `path2'; false otherwise. */

CG_EXTERN bool CGPathEqualToPath(CGPathRef path1, CGPathRef path2)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/*** Path construction functions. ***/

/* Move the current point to `(x, y)' in `path' and begin a new subpath. If
   `m' is non-NULL, then transform `(x, y)' by `m' first. */

CG_EXTERN void CGPathMoveToPoint(CGMutablePathRef path,
    const CGAffineTransform *m, CGFloat x, CGFloat y)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Append a straight line segment from the current point to `(x, y)' in
   `path' and move the current point to `(x, y)'. If `m' is non-NULL, then
   transform `(x, y)' by `m' first. */

CG_EXTERN void CGPathAddLineToPoint(CGMutablePathRef path,
    const CGAffineTransform *m, CGFloat x, CGFloat y)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Append a quadratic curve from the current point to `(x, y)' with control
   point `(cpx, cpy)' in `path' and move the current point to `(x, y)'. If
   `m' is non-NULL, then transform all points by `m' first. */

CG_EXTERN void CGPathAddQuadCurveToPoint(CGMutablePathRef path,
    const CGAffineTransform *m, CGFloat cpx, CGFloat cpy, CGFloat x, CGFloat y)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Append a cubic Bézier curve from the current point to `(x,y)' with
   control points `(cp1x, cp1y)' and `(cp2x, cp2y)' in `path' and move the
   current point to `(x, y)'. If `m' is non-NULL, then transform all points
   by `m' first. */

CG_EXTERN void CGPathAddCurveToPoint(CGMutablePathRef path,
    const CGAffineTransform *m, CGFloat cp1x, CGFloat cp1y,
    CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Append a line from the current point to the starting point of the current
   subpath of `path' and end the subpath. */

CG_EXTERN void CGPathCloseSubpath(CGMutablePathRef path)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/*** Path construction convenience functions. ***/

/* Add `rect' to `path'. If `m' is non-NULL, then first transform `rect' by
   `m' before adding it to `path'. */

CG_EXTERN void CGPathAddRect(CGMutablePathRef path, const CGAffineTransform *m,
    CGRect rect) CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Add each rectangle specified by `rects', an array of `count' CGRects, to
   `path'. If `m' is non-NULL, then first transform each rectangle by `m'
   before adding it to `path'. */

CG_EXTERN void CGPathAddRects(CGMutablePathRef path,
    const CGAffineTransform *m, const CGRect rects[], size_t count)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Move to the first element of `points', an array of `count' CGPoints, and
   append a line from each point to the next point in `points'. If `m' is
   non-NULL, then first transform each point by `m'. */

CG_EXTERN void CGPathAddLines(CGMutablePathRef path,
    const CGAffineTransform *m, const CGPoint points[], size_t count)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Add an ellipse (an oval) inside `rect' to `path'. The ellipse is
   approximated by a sequence of Bézier curves. The center of the ellipse is
   the midpoint of `rect'. If `rect' is square, then the ellipse will be
   circular with radius equal to one-half the width (equivalently, one-half
   the height) of `rect'. If `rect' is rectangular, then the major- and
   minor-axes will be the `width' and `height' of rect. The ellipse forms a
   complete subpath of `path' --- that is, it begins with a "move to" and
   ends with a "close subpath" --- oriented in the clockwise direction. If
   `m' is non-NULL, then the constructed Bézier curves representing the
   ellipse will be transformed by `m' before they are added to `path'. */

CG_EXTERN void CGPathAddEllipseInRect(CGMutablePathRef path,
    const CGAffineTransform *m, CGRect rect)
    CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* Add an arc of a circle to `path', possibly preceded by a straight line
   segment. The arc is approximated by a sequence of Bézier curves. `(x, y)'
   is the center of the arc; `radius' is its radius; `startAngle' is the
   angle to the first endpoint of the arc; `endAngle' is the angle to the
   second endpoint of the arc; and `clockwise' is true if the arc is to be
   drawn clockwise, false otherwise. `startAngle' and `endAngle' are
   measured in radians. If `m' is non-NULL, then the constructed Bézier
   curves representing the arc will be transformed by `m' before they are
   added to `path'. */

CG_EXTERN void CGPathAddArc(CGMutablePathRef path, const CGAffineTransform *m,
    CGFloat x, CGFloat y, CGFloat radius, CGFloat startAngle, CGFloat endAngle,
    bool clockwise) CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Add an arc of a circle to `path', possibly preceded by a straight line
   segment. The arc is approximated by a sequence of Bézier curves. `radius'
   is the radius of the arc. The resulting arc is tangent to the line from
   the current point of `path' to `(x1, y1)', and the line from `(x1, y1)'
   to `(x2, y2)'. If `m' is non-NULL, then the constructed Bézier curves
   representing the arc will be transformed by `m' before they are added to
   `path'. */

CG_EXTERN void CGPathAddArcToPoint(CGMutablePathRef path,
    const CGAffineTransform *m, CGFloat x1, CGFloat y1, CGFloat x2, CGFloat y2,
    CGFloat radius) CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Add `path2' to `path1'. If `m' is non-NULL, then the points in `path2'
   will be transformed by `m' before they are added to `path1'. */

CG_EXTERN void CGPathAddPath(CGMutablePathRef path1,
    const CGAffineTransform *m, CGPathRef path2)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/*** Path information functions. ***/

/* Return true if `path' contains no elements, false otherwise. */

CG_EXTERN bool CGPathIsEmpty(CGPathRef path)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Return true if `path' represents a rectangle, false otherwise. */

CG_EXTERN bool CGPathIsRect(CGPathRef path, CGRect *rect)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Return the current point of the current subpath of `path'. If there is no
   current point, then return CGPointZero. */

CG_EXTERN CGPoint CGPathGetCurrentPoint(CGPathRef path)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Return the bounding box of `path'. The bounding box is the smallest
   rectangle completely enclosing all points in the path, including control
   points for Bézier cubic and quadratic curves. If the path is empty, then
   return `CGRectNull'. */

CG_EXTERN CGRect CGPathGetBoundingBox(CGPathRef path)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Return the path bounding box of `path'. The path bounding box is the
   smallest rectangle completely enclosing all points in the path, *not*
   including control points for Bézier cubic and quadratic curves. If the
   path is empty, then return `CGRectNull'. */

CG_EXTERN CGRect CGPathGetPathBoundingBox(CGPathRef path)
  CG_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);

/* Return true if `point' is contained in `path'; false otherwise. A point
   is contained in a path if it is inside the painted region when the path
   is filled; if `eoFill' is true, then the even-odd fill rule is used to
   evaluate the painted region of the path, otherwise, the winding-number
   fill rule is used. If `m' is non-NULL, then the point is transformed by
   `m' before determining whether the path contains it. */

CG_EXTERN bool CGPathContainsPoint(CGPathRef path,
    const CGAffineTransform *m, CGPoint point, bool eoFill)
    CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* The types of path elements returned by `CGPathApply'. */

enum CGPathElementType {
    kCGPathElementMoveToPoint,
    kCGPathElementAddLineToPoint,
    kCGPathElementAddQuadCurveToPoint,
    kCGPathElementAddCurveToPoint,
    kCGPathElementCloseSubpath
};
typedef enum CGPathElementType CGPathElementType;

/* An element of a path returned by `CGPathApply'. */

struct CGPathElement {
    CGPathElementType type;
    CGPoint *points;
};
typedef struct CGPathElement CGPathElement;

/* The prototype for the function called by `CGPathApplyFunction'. */

typedef void (*CGPathApplierFunction)(void *info,
    const CGPathElement *element);

/* For element of `path', call `function', passing it the path element and
   `info'. */

CG_EXTERN void CGPathApply(CGPathRef path, void *info,
    CGPathApplierFunction function)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

#endif	/* CGPATH_H_ */
