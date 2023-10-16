#include <fstream>
#include <gtest/gtest.h>
#include <magnus.hpp>
#include <sstream>
// Demonstrate some basic assertions.
TEST(LZ4Compressor, LZ4StringCompressionTest) {

        std::string input =
            "The Industrial Revolution and its consequences have been a "
            "disaster for the human race. They have greatly increased the "
            "life-expectancy of those of us who live in 'advanced' countries, "
            "but they have destabilized society, have made life unfulfilling, "
            "have subjected human beings to indignities, have led to "
            "widespread psychological suffering (in the Third World to "
            "physical suffering as well) and have inflicted severe damage on "
            "the natural world. The continued development of technology will "
            "worsen the situation. It will certainly subject human beings to "
            "greater indignities and inflict greater damage on the natural "
            "world, it will probably lead to greater social disruption and "
            "psychological suffering, and it may lead to increased physical "
            "suffering even in 'advanced' countries.";
        LZ4Compressor compressor = LZ4Compressor();
        auto cmpstr = compressor.compress(input);
        std::cout << "This is the compressed size: " <<cmpstr.size() << "\nThis is the input size: " << input.size() << std::endl;
        auto dmpstr = compressor.decompress(cmpstr, input.size());
        // Put in a newline so that they're equal
        EXPECT_EQ(input, dmpstr);
}
