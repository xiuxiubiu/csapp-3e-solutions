int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return (ux << 1 == 0 && uy << 1 == 0) || /* both zeros */
    (sx && !sy) ||                         /* x < 0, y >= 0 or x <= 0, y > 0 */
    (!sx && !sy && ux <= uy) ||            /* x > 0, y >= 0 or x >= 0, y > 0 */
    (sx && sy && ux >= uy);                /* x < 0, y <= 0 or x <= 0, y < 0 */
}