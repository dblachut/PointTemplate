# PointTemplate
Point template written using C++11 features (std::array and std::initializer_list).

Supporting array notation element access. All methods (including constructor) can be used with parameter list, std::array or std::initializer_list, and another point of the same type.

## Example usage:
```cpp
Point<int, 2> pi2_1;
Point<int, 2> pi2_2(7, 65);
Point<int, 2> pi2_3({ 34, 65 });

Point<double, 4> pd4_1;
Point<double, 4> pd4_2(3, 4, 8, 15);
Point<double, 4> pd4_3({3, 4, 8, 15});

if (!pd4_1.equals(pd4_2)) {
    pd4_3[X] = pd4_3[Y];
    pd4_3[Z] = pd4_1.distanceTo(3, 6, 7, 1);
}
```
