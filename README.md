
# Run-Length Encoding (RLE)

Run-Length Encoding (RLE) is a lossless data compression algorithm, meaning that it reduces the size of data without losing any of the original information.
Instead of storing every repeated character individually, RLE stores how many times a character appears consecutively.

### Original Input
```text
AAAAABBBCCCCCCDD
```

### RLE Compressed Output
```text
5A3B6C2D
```

## How it works

The algorithm is pretty simple:
  1. Start at the first character
  2. Count how many times it appears consecutively
  3. Store the count and character
  4. Move on to the next different character
  5. Repeat until reaching the end

RLE works best when data contains long sequences of repeated values

## Real World Uses

Simple Images and Graphics
  - Large areas of identical pixels can be represented using counts instead of storing each pixel separately.

Fax and document compression
  - Black-and-white documents often contain long runs of white or black pixels, making run-length techniques useful.

## Example where RLE doesn't work well:

```text
Original:   ABCDEF
Compressed: 1A1B1C1D1E1F
```

## Time and Space Complexity

For an input containing _m_ characters:
- Compression time: O(n), using an efficient output buffer.
- Decompression time: O(m), where _m_ is the decompressed output length.
- Space complexity: O(n) for storing the compressed output in the worst case.


## Implementation

This project includes a C implementation of Run-Length Encoding (RLE) that demonstrates both compression and decompression.

The program contains four main functions:

- `rle_encode()` - Compresses a string by replacing consecutive repeated characters with their count and character.
- `rle_decode()` - Reconstructs the original string from its compressed representation.
- `compression_stats()` - Calculates the original size, compressed size, and percentage reduction.
- `test_rle()` - Tests compression and decompression and verifies that no information was lost.

The program demonstrates RLE using three different inputs to show how the effectiveness of compression depends on the amount of repetition.

## How to Run

### 1. Clone the repository

```bash
git clone https://github.com/ethanle-11/datacompression-RLE-checkoff.git
cd datacompression-RLE-checkoff
```

### 2. Compile the program

Make sure GCC is installed.

```bash
gcc src/rle.c -o rle
```

### 3. Run the program

```bash
./rle
```

### Example Results

| Original Input | Compressed Output | Size Reduction |
|----------------|-------------------|----------------|
| `AAAAABBBCC` | `5A3B2C` | 40% |
| `AAAAAAAAAA` | `10A` | 70% |
| `ABCDE` | `1A1B1C1D1E` | -100% |

The results demonstrate that RLE is most effective for highly repetitive data. When there are few or no repeated characters, the compressed representation can actually be larger than the original.

The program also verifies that decompression produces the original string exactly.
