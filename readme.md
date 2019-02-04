## Cuboid - A 3D graphics and linear algebra library for the CE

Cuboid provides an easy way to enable 3D graphics on the CE calculator, albeit
with somewhat poor performance due to the limitations of the calculator.

### Installation

If you want to use Cuboid with your projects, simple add the contents of the src
folder into your own projects' src folder. You can create another folder inside
src if you like, but be sure to update your header includes to reflect that.

---

### Basic Ideas

#### Vectors

A point is 3D space is represented by a vector, with x, y, and z components.
The library has support for basic vector arithmetic, such as addition,
subtraction, dot products, and cross products.

#### Matrices

A matrix is used to perform linear transformations on vectors. Generally, they
can be thought of as ways of "stretching" or moving vectors around. They can be
created from either arrays of length at least 9 or multi-dimensional arrays of
3x3.

#### Pixels

A point on the 2D screen is represented by a pixel, with an x and y component.
Note that larger y values correspond to going down on the screen rather than
going up like on a Cartesian plane.

#### Projections

The idea of the projection is fundamental to the functionality of the library.
Projections take 3D vectors and output a 2D pixel, which can then be drawn on
screen. Currently, there is only support for orthographic projections, but
in theory, perspective, isometric, and other types of projections could be
added in the future.

---

### Using the library

#### Creating components
Components (vectors, pixels, matrices, etc.) can be created by invoking the
newComponentName() functions and passing in the proper parameters (replace
componentName with whatever you are creating). This ensures that the proper
memory is allocated to the component. Remember to free the addresses if you are
done using them.

#### Writing your own Projections
Custom projections can be written to do whatever you want, but must follow the
format of projectionName(vector_t, pixel_t, float*), which define the vector to
be projected, the pixel to consider as the origin, and a float pointer, which
is used to pass in any custom parameters you want to have in your projection
that is left up to the user.
