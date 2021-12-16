#ifndef DAY_003_H_
#define DAY_003_H_
#include <cstdint>
#include <list>



uint32_t constexpr NUMBER_VALUES = 1000;
uint32_t constexpr NUMBER_BITS = 12; //5

class Submarine
{
private:
    uint32_t buffer_array_number_high_bits[NUMBER_BITS];
    bool is_bit_high(uint32_t value, int bit)
    {
        return (value & (1U << (NUMBER_BITS-bit-1)))!=0;
    }
    
public:
    uint32_t get_sums(std::list<uint32_t>& list);
    void print_list(std::list<uint32_t>& list);
    bool add_nodes(std::list<uint32_t>&  from, std::list<uint32_t>& to, int bit, bool high);
    bool prune_nodes(std::list<uint32_t>& list_to_prune, int bit, bool to_keep_bit);
    uint32_t get_bit_array_value(int bit)
    {
        return buffer_array_number_high_bits[bit];
    }

    // To find oxygen generator rating:
    //      determine the most common value (0 or 1) in the current bit position, 
    //      and keep only numbers with that bit in that position. If 0 and 1 are 
    //      equally common, keep values with a 1 in the position being considered.
    void get_oxygen_rating(int bit);


    // To find CO2 scrubber rating:
    //      determine the least common value (0 or 1) in the current bit position, 
    //      and keep only numbers with that bit in that position. If 0 and 1 are 
    //      equally common, keep values with a 0 in the position being considered.
    void get_co2_rating(int bit);
    
    Submarine(/* args */){};
    ~Submarine(){};
};

// uint32_t constexpr VALUES[NUMBER_VALUES]={
std::list<uint32_t> VALUES={
0b000001110001,
0b000001111101,
0b010011000000,
0b000000000011,
0b010000100111,
0b101000100001,
0b101000001101,
0b010011001111,
0b001000111011,
0b110010110011,
0b010110110000,
0b110000111100,
0b111110101000,
0b100011001101,
0b100100000001,
0b101100011011,
0b110111111100,
0b010110101011,
0b000010010001,
0b100000000111,
0b100000111100,
0b111011100010,
0b101010001101,
0b111011110000,
0b111010001101,
0b010010110110,
0b000101011011,
0b001101101110,
0b101100100000,
0b101010111101,
0b100010010111,
0b000100100101,
0b001000100011,
0b000001011111,
0b000100001101,
0b011111100101,
0b101001110011,
0b100010000001,
0b010111010100,
0b100101101001,
0b100001001000,
0b110011010111,
0b010111010001,
0b111000011010,
0b110101100100,
0b011100001000,
0b001010000000,
0b011111001010,
0b010111110111,
0b100000000001,
0b111011101011,
0b100000100010,
0b111110100110,
0b001000000001,
0b100001111110,
0b000110010110,
0b011001101010,
0b101111001011,
0b010010010100,
0b000110110111,
0b001000011111,
0b100111001110,
0b111110111111,
0b100000010010,
0b110111111001,
0b000111011100,
0b100100000010,
0b111000110001,
0b000011101010,
0b010111111011,
0b101010111000,
0b010101001101,
0b000010101101,
0b001000000111,
0b011111101110,
0b010011100010,
0b100010100000,
0b001101000011,
0b010011101010,
0b111100000011,
0b001100010010,
0b011111100001,
0b000001101101,
0b011011100010,
0b010011010000,
0b111010001011,
0b100111011101,
0b011110010110,
0b001110010100,
0b010001110101,
0b001011011100,
0b001111011101,
0b111111000001,
0b100101001111,
0b110111011111,
0b001110100010,
0b111111111110,
0b001101111010,
0b001110001101,
0b001001110100,
0b100000110000,
0b001100000001,
0b100001101100,
0b110100110011,
0b111101100000,
0b000000000001,
0b000010101100,
0b101000000011,
0b110011110100,
0b000001010011,
0b001101010111,
0b100001101011,
0b111000101011,
0b000100010001,
0b011111101010,
0b010110011011,
0b110111110000,
0b100110111111,
0b110111000011,
0b110100101011,
0b110011011001,
0b101101001010,
0b101110111100,
0b101010110010,
0b011111110000,
0b100000011010,
0b010100011111,
0b100001111011,
0b100000000000,
0b100101000111,
0b001111010111,
0b110111111010,
0b011011011111,
0b111101000101,
0b101111000111,
0b101111000001,
0b010100101110,
0b001001101110,
0b100001011000,
0b100100010000,
0b111111111011,
0b111000000100,
0b000010111000,
0b010111111100,
0b111110001100,
0b011001111011,
0b101011100111,
0b111101001001,
0b001111100011,
0b101000101110,
0b010001101001,
0b001101001110,
0b011011000110,
0b111000000000,
0b010010001100,
0b111011000110,
0b011011001011,
0b111000000011,
0b110110001110,
0b001001101001,
0b100011010101,
0b100101111011,
0b101111110001,
0b011001011011,
0b111101000100,
0b110000100001,
0b010001000110,
0b011000101101,
0b000101001001,
0b000011111100,
0b010001110011,
0b111111100010,
0b000110010000,
0b101101001101,
0b110000010111,
0b000010010010,
0b001110111001,
0b110011001111,
0b000010110010,
0b010010000110,
0b101100101100,
0b111111011100,
0b000111011111,
0b011011111001,
0b011100101011,
0b100011010110,
0b011101011111,
0b010000010111,
0b000110111001,
0b010010111010,
0b010011101000,
0b011010101110,
0b011100111101,
0b010110110011,
0b011110100100,
0b100000100011,
0b100001001011,
0b001000111110,
0b101101001011,
0b101111101000,
0b001011000111,
0b101111101110,
0b101001100011,
0b110010110010,
0b101111010001,
0b110100010000,
0b100011000010,
0b001010110010,
0b110111101101,
0b000010001000,
0b001101100000,
0b101110101001,
0b000111000000,
0b011010101000,
0b100111110011,
0b111110000011,
0b111101111011,
0b100111110110,
0b110100000111,
0b101100111001,
0b011111000001,
0b110110101111,
0b111011100101,
0b000001001111,
0b001111001010,
0b010110010100,
0b000001010001,
0b111101111110,
0b101010000110,
0b001111011100,
0b110001101010,
0b101011110101,
0b001001001011,
0b101100010101,
0b101011101011,
0b100010110011,
0b101001011111,
0b101010010100,
0b100001110011,
0b001110000101,
0b011110111110,
0b111010111111,
0b100110011001,
0b010101111100,
0b000101010100,
0b111101101001,
0b011100011010,
0b001000111010,
0b011111010011,
0b100010001010,
0b000111010011,
0b010011100000,
0b011011001000,
0b001011101110,
0b001001111100,
0b111000011101,
0b101011111101,
0b110000110110,
0b100010111001,
0b010111101000,
0b100101101101,
0b011011011000,
0b010101010011,
0b011010000001,
0b000001101011,
0b101001110000,
0b101111111100,
0b000111100001,
0b010111010110,
0b010110000000,
0b101010100100,
0b010011110000,
0b111011000100,
0b110010100111,
0b101101011111,
0b011011101100,
0b000011101110,
0b011001100000,
0b010110111011,
0b100110011000,
0b111101000011,
0b000111011001,
0b001101011110,
0b010000100110,
0b111011100001,
0b001100100101,
0b110110001001,
0b111101001111,
0b000111011000,
0b001110011010,
0b101000000000,
0b111110011100,
0b000100110000,
0b100001110010,
0b101101011000,
0b101001100110,
0b010000101110,
0b010110111100,
0b111000100100,
0b110101101000,
0b001111010100,
0b110111010000,
0b110010011100,
0b110111000110,
0b010100010011,
0b001000010111,
0b100111101001,
0b100110101011,
0b101010000100,
0b111000010001,
0b001001010011,
0b100100111001,
0b010000010011,
0b010110010110,
0b100101100010,
0b011010011100,
0b101101011110,
0b100110101111,
0b011100011100,
0b011000110110,
0b001000001110,
0b101011111001,
0b011001001011,
0b000100111101,
0b011111110100,
0b101000110001,
0b110111011000,
0b100100010111,
0b000111111100,
0b110001110101,
0b111001001000,
0b101000011110,
0b110111100101,
0b010010001010,
0b100110100010,
0b111100011010,
0b110111100110,
0b011100110110,
0b110100111000,
0b011110010010,
0b110100010001,
0b010010100000,
0b010100000000,
0b010110110010,
0b110111111101,
0b101000000110,
0b100010101000,
0b111101000010,
0b001011010001,
0b010011111110,
0b000001010000,
0b100101001011,
0b011000110001,
0b001111101011,
0b000001110010,
0b101010101010,
0b011011010000,
0b011011001101,
0b111001000100,
0b110111001010,
0b000111010100,
0b000111111101,
0b010111000110,
0b010100010111,
0b010001001010,
0b001001010110,
0b101111001110,
0b000111100000,
0b110111000100,
0b001001000001,
0b011111110111,
0b101111000100,
0b110100011010,
0b100000111010,
0b000000011101,
0b001010010100,
0b001000001100,
0b001101101010,
0b011110110001,
0b100101011101,
0b101000101001,
0b101010000011,
0b100111100001,
0b001011001000,
0b000111111001,
0b000011110101,
0b111111110000,
0b100010000101,
0b001100111000,
0b001001011011,
0b001111111110,
0b011000110111,
0b110111001110,
0b111001111101,
0b000111010000,
0b001110100011,
0b100111111000,
0b111011110010,
0b001000110101,
0b110101111111,
0b101110001000,
0b100100000000,
0b101001110100,
0b000100010011,
0b001110110010,
0b011011000111,
0b011110011100,
0b111010110011,
0b100011010000,
0b101110100001,
0b101011001110,
0b010101011000,
0b101100011101,
0b011100000111,
0b101010010011,
0b000101000000,
0b111000000110,
0b110010001001,
0b001111111010,
0b010001101110,
0b111011100110,
0b010111101011,
0b101111010100,
0b011111110101,
0b010110110001,
0b000100101011,
0b101010101001,
0b111110110010,
0b011110000010,
0b111001001101,
0b101100110110,
0b011000001110,
0b001110000111,
0b100001000001,
0b100111110010,
0b101101101111,
0b000110011001,
0b000000110011,
0b111110001101,
0b000000111100,
0b101111100010,
0b100110100001,
0b011110110110,
0b101011110100,
0b101101110100,
0b011111110011,
0b110110011110,
0b111010001110,
0b100101110000,
0b100000111101,
0b001011010110,
0b101001111100,
0b000010011001,
0b000111010001,
0b100000101010,
0b100010011000,
0b100100001000,
0b001010100001,
0b111100001011,
0b110000000110,
0b111011000111,
0b000000111010,
0b101100000111,
0b010111010010,
0b011001011100,
0b000011100010,
0b110111101010,
0b111111010001,
0b100011111000,
0b111111100101,
0b110011110101,
0b100110001010,
0b101011101111,
0b111111100110,
0b101111110010,
0b110000010001,
0b110001100100,
0b101100110001,
0b011010111001,
0b001000111111,
0b110110001000,
0b011110001011,
0b000100010101,
0b010101100100,
0b000001001000,
0b000000010101,
0b100000101101,
0b010000000100,
0b010110000110,
0b111100110010,
0b100010001101,
0b011001111010,
0b100000111011,
0b110111101110,
0b111000100010,
0b101011010010,
0b111000011011,
0b001101000111,
0b110011111100,
0b110101010101,
0b010100101010,
0b110110010110,
0b101011100000,
0b111101111010,
0b101000011000,
0b000101011000,
0b111010000001,
0b000100000010,
0b100110000100,
0b010111100001,
0b110001010101,
0b110011111101,
0b110000101010,
0b011100111110,
0b011010100100,
0b000111100011,
0b101000000111,
0b011110101110,
0b001111001110,
0b110010010010,
0b010010111111,
0b111110011011,
0b110110111011,
0b111000111011,
0b010100100000,
0b100001010110,
0b010010011111,
0b010000101010,
0b011011110101,
0b001101101101,
0b101110111110,
0b001101101000,
0b110100110010,
0b011010010011,
0b011011011110,
0b011010101100,
0b010101010010,
0b101110000000,
0b000001011011,
0b110100101010,
0b110010001111,
0b111011111110,
0b000101100010,
0b110000010011,
0b111110001010,
0b000101100100,
0b110001110100,
0b011101111110,
0b011010001001,
0b110110101101,
0b011111101101,
0b111111101101,
0b111001101000,
0b011110100110,
0b111011011001,
0b010001110010,
0b101001110111,
0b010011110100,
0b011011001010,
0b110100011101,
0b111001111001,
0b010001100111,
0b011100110000,
0b101110001101,
0b000100111111,
0b001100100111,
0b000010111001,
0b110000100101,
0b010101101101,
0b100100110111,
0b111110111100,
0b100000101111,
0b011110110111,
0b100010001110,
0b001000000110,
0b111110110110,
0b001100100010,
0b000011111111,
0b010000100010,
0b000101111100,
0b001000100111,
0b011001000110,
0b110001111110,
0b001001011010,
0b101111101111,
0b001000010100,
0b100100001100,
0b001010101100,
0b110100000101,
0b001011101000,
0b101011100101,
0b011011111100,
0b111000111100,
0b110000001101,
0b010011010101,
0b001001110110,
0b110110101011,
0b101100010111,
0b011000010101,
0b010100011000,
0b010001001100,
0b010101110101,
0b110100100110,
0b111111101011,
0b000110010111,
0b100100110001,
0b001111000011,
0b010100000010,
0b011101101010,
0b010111110101,
0b011101011001,
0b101111010010,
0b000000010110,
0b100000100000,
0b010001011010,
0b000110011111,
0b110000110111,
0b111001110011,
0b110100111110,
0b000000001001,
0b001000110001,
0b000110000101,
0b010110100000,
0b001100010100,
0b101010100101,
0b111100001100,
0b111010110110,
0b000001100111,
0b001011011110,
0b000100100001,
0b111001111000,
0b110001011001,
0b110101110101,
0b101010110101,
0b000011001010,
0b001010110000,
0b101111110101,
0b101001111001,
0b100010111101,
0b001110101001,
0b110011110111,
0b101011001001,
0b010001111100,
0b000101100011,
0b011110001100,
0b111111110101,
0b010010011001,
0b111000110111,
0b100110100000,
0b010110110100,
0b011111111110,
0b001111101100,
0b100010010010,
0b101110010110,
0b111010000101,
0b011011000100,
0b101000011001,
0b001000001101,
0b010110100111,
0b000000011010,
0b111101110000,
0b000100000001,
0b101000000010,
0b011110101111,
0b100010001111,
0b101101110101,
0b111110011101,
0b001111111011,
0b110000101100,
0b000111100010,
0b101111011111,
0b011101101111,
0b001011000101,
0b100110101110,
0b010100100001,
0b010000011111,
0b010100011001,
0b011010100110,
0b011010110111,
0b101011101101,
0b011101000001,
0b010111011011,
0b000010011100,
0b011111011000,
0b110011010100,
0b011101101110,
0b000100110100,
0b010010111100,
0b110000101000,
0b010000110001,
0b111011111001,
0b110001101001,
0b010101001010,
0b111001010111,
0b111001100000,
0b010111000111,
0b111011001101,
0b001111011110,
0b110100110111,
0b110001010100,
0b100001011010,
0b101100001010,
0b111111001101,
0b111000010000,
0b001001011101,
0b111110100101,
0b011110001110,
0b111001101001,
0b111011010001,
0b001100001111,
0b001110101111,
0b010011111011,
0b001001100001,
0b010100111010,
0b110000010101,
0b011000001010,
0b001111101111,
0b111000000101,
0b011011000011,
0b111110010101,
0b011000000111,
0b010111000000,
0b001100010000,
0b110001100010,
0b110011011100,
0b101001101111,
0b010010101111,
0b011110101000,
0b001000111100,
0b100101110110,
0b100100101011,
0b100101000110,
0b110100000100,
0b001111110001,
0b010001000100,
0b110011011111,
0b110110110001,
0b010001111001,
0b101000011101,
0b111111101100,
0b001111110100,
0b111100011100,
0b110111011011,
0b000001001011,
0b001011000100,
0b000000010100,
0b010001100010,
0b010010001001,
0b101011101110,
0b000010000000,
0b010101010000,
0b101001000000,
0b111010101011,
0b000101111000,
0b101100101011,
0b111001100100,
0b001011000011,
0b010111101100,
0b000100111110,
0b000111111111,
0b010001010000,
0b110110000001,
0b110101110100,
0b001010100110,
0b101110011011,
0b011110001101,
0b011100100001,
0b111110010110,
0b100100100001,
0b110010011001,
0b001010110100,
0b011011110010,
0b001110110001,
0b010100110111,
0b100000111001,
0b100001011110,
0b011011011100,
0b101110000111,
0b000001011010,
0b000000111000,
0b001001111111,
0b110101101001,
0b010011001100,
0b101011100100,
0b000011111101,
0b011100100010,
0b000010111011,
0b111000010111,
0b101101011101,
0b100001010011,
0b010001000000,
0b111110001011,
0b111101110010,
0b100001101110,
0b100000111000,
0b010101010101,
0b100110110001,
0b010001101000,
0b110001011011,
0b011011010001,
0b011101000000,
0b101101011100,
0b001101001001,
0b101001100000,
0b111011111000,
0b110101111000,
0b011001110101,
0b011000111000,
0b000011010100,
0b011010010101,
0b000010110110,
0b110001101000,
0b000001111011,
0b000101110001,
0b000110100011,
0b011111000101,
0b101010011001,
0b110000011011,
0b010010101101,
0b110101000100,
0b111001100011,
0b010001100001,
0b111001111111,
0b000000101110,
0b111010000111,
0b100100000100,
0b111110111001,
0b101100011000,
0b101111010110,
0b010110111111,
0b100001000110,
0b110000110011,
0b101000001111,
0b000001001010,
0b001100110100,
0b100000110101,
0b010111110010,
0b010011011011,
0b110101101101,
0b010100111100,
0b000010101011,
0b111100001101,
0b101001000011,
0b001101110111,
0b011001010001,
0b111100111001,
0b011100111010,
0b111010010010,
0b000101111011,
0b000001110101,
0b110110100001,
0b111100110011,
0b110110101010,
0b110101010010,
0b000000010000,
0b100100010010,
0b001000100110,
0b010000110101,
0b111011000000,
0b101101100001,
0b000110001101,
0b110110110110,
0b000010001101,
0b010001101100,
0b000000001000,
0b000110101011,
0b001000011101,
0b001111110000,
0b000100000100,
0b010111110110,
0b111111110110,
0b101110100000,
0b011010010111,
0b111111101111,
0b011010100001,
0b110101111010,
0b000010010111,
0b011001011000,
0b111010101010,
0b100101100100,
0b010110100101,
0b011110111000,
0b101001010110,
0b101111001100,
0b001111001000,
0b011100101100,
0b101100000010,
0b110011100100,
0b101001101000,
0b110110000110,
0b000111101011,
0b111110001000,
0b001011110000,
0b001001100000,
0b000111110111,
0b000101111010,
0b001010000110,
0b011100000000,
0b110100001000,
0b111001001110,
0b010111001100,
0b101111111001,
0b110010110111,
0b010101010111,
0b100111100110,
0b110010100100,
0b001011101100,
0b110111001111,
0b001001100111,
0b010011101110,
0b001101000100,
0b000010111101,
0b111101101110,
0b111011011101,
0b100101110100,
0b101110110110,
0b000110101101,
0b110100100011,
0b001001010010,
0b111000101111,
0b000010011110,
0b001101110011,
0b111010010001,
0b010110001110,
0b010000110100,
0b010101111001,
0b001010011011,
0b010110100001,
0b000001100110,
0b100101111101,
0b110000000101,
0b010001010010,
0b111101110100,
0b001000011010,
0b011011001001,
0b010010010000,
0b111111001100,
0b001001011111,
0b010001100100,
0b100011111011,
0b011000011100,
0b100011011001,
0b011111100111,
0b110111101001,
0b011011110111,
0b010100000110,
0b011011001100,
0b000000101111,
0b100000100100,
0b101011001010,
0b101101001111,
0b000011111010,
0b011101111010,
0b000011110100,
0b001011111110,
0b101000010010,
0b010000110010,
0b001000000000,
0b011001111100,
0b111111000011,
0b010101000000,
0b110001111010,
0b101001101101,
0b001011000001,
0b110010101010,
0b110111110101,
0b010100110110,
0b101010111001,
0b010111100110,
0b101001000110,
0b000011001000,
0b110000001010,
0b110001100110,
0b111100011110,
0b100100101111,
0b001110001001,
0b011011111010,
0b000011000001,
0b001111011011,
0b000110000011,
0b010010100111,
0b110010001010,
0b011100011001,
0b101111101011,
0b001100000100,
0b101100101111,
0b000101001100,
0b010100010100,
0b100100010001,
0b100111111110,
0b010111100111,
0b001000011000,
0b101010001001,
0b110000110100,
0b111110110001,
0b100110100101,
0b101000010100,
0b100011000000,
0b001110100100,
0b110000110001};

#endif // DAY_003_H_ 