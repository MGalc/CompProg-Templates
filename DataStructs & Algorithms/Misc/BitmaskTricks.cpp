// To go over all permutations of 1's in a bitmask of 0b011010
// 0b011010
// 0b011000
// 0b010010
// 0b010000
// 0b001010
// 0b001000
// 0b000010
// 0b000000
//
// We can do: 
int perm = bitmask;
for (int perm = bitmask; perm != 0; (perm - 1) & bitmask) {
    // Use permutation here
}
