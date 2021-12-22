long switch_prob(long x, long n)
{
    long result = x;
    switch (n) {
        case 63:
            result = x >> 3;
            break;
        case 64:
            result = x * 15;
            x = n;
        case 65:
            x = x*x;
        case 61:
            result = x + 0x4b;
            break;
        default:
            result = 8 * x;

    }
    return result;
}