//
// Created by halid on 07/05/2023.
//

#include <gtest/gtest.h>

#include "bitmanip.h"

using namespace lll;

TEST(Bitman, Check) {

    uint8_t  u8 {0b11110000};
    uint16_t u16{0b1111000011110000};
    uint32_t u32{0b11110000111100001111000011110000};
    uint64_t u64{0b1111000011110000111100001111000011110000111100001111000011110000};

    EXPECT_EQ(bitmanip::check(u8, 0), 0);
    EXPECT_EQ(bitmanip::check(u8, 4), 1);

    EXPECT_EQ(bitmanip::check(u16, 15), 1);
    EXPECT_EQ(bitmanip::check(u16, 7), 1);

    EXPECT_EQ(bitmanip::check(u32, 26), 0);
    EXPECT_EQ(bitmanip::check(u32, 30), 1);

    EXPECT_EQ(bitmanip::check(u64, 62), 1);
    EXPECT_EQ(bitmanip::check(u64, 57), 0);
}

TEST(Bitman, Set) {

    uint8_t  u8 {0b11110000};
    uint16_t u16{0b1111000011110000};
    uint32_t u32{0b11110000111100001111000011110000};
    uint64_t u64{0b1111000011110000111100001111000011110000111100001111000011110000};

    bitmanip::set(u8, 0);
    EXPECT_EQ(bitmanip::check(u8, 0), 1);

    bitmanip::set(u8, 4);
    EXPECT_EQ(bitmanip::check(u8, 4), 1);

    bitmanip::set(u16, 15);
    EXPECT_EQ(bitmanip::check(u16, 15), 1);

    bitmanip::set(u16, 7);
    EXPECT_EQ(bitmanip::check(u16, 7), 1);

    bitmanip::set(u32, 26);
    EXPECT_EQ(bitmanip::check(u32, 26), 1);

    bitmanip::set(u32, 30);
    EXPECT_EQ(bitmanip::check(u32, 30), 1);

    bitmanip::set(u64, 62);
    EXPECT_EQ(bitmanip::check(u64, 62), 1);

    bitmanip::set(u64, 57);
    EXPECT_EQ(bitmanip::check(u64, 57), 1);
}

TEST(Bitman, Clear) {

    uint8_t  u8 {0b11110000};
    uint16_t u16{0b1111000011110000};
    uint32_t u32{0b11110000111100001111000011110000};
    uint64_t u64{0b1111000011110000111100001111000011110000111100001111000011110000};

    bitmanip::clear(u8, 0);
    EXPECT_EQ(bitmanip::check(u8, 0), 0);

    bitmanip::clear(u8, 4);
    EXPECT_EQ(bitmanip::check(u8, 4), 0);

    bitmanip::clear(u16, 15);
    EXPECT_EQ(bitmanip::check(u16, 15), 0);

    bitmanip::clear(u16, 7);
    EXPECT_EQ(bitmanip::check(u16, 7), 0);

    bitmanip::clear(u32, 26);
    EXPECT_EQ(bitmanip::check(u32, 26), 0);

    bitmanip::clear(u32, 30);
    EXPECT_EQ(bitmanip::check(u32, 30), 0);

    bitmanip::clear(u64, 62);
    EXPECT_EQ(bitmanip::check(u64, 62), 0);

    bitmanip::clear(u64, 57);
    EXPECT_EQ(bitmanip::check(u64, 57), 0);
}

TEST(Bitman, Toggle) {

    uint8_t  u8 {0b11110000};
    uint16_t u16{0b1111000011110000};
    uint32_t u32{0b11110000111100001111000011110000};
    uint64_t u64{0b1111000011110000111100001111000011110000111100001111000011110000};

    bool before;

    before = bitmanip::check(u8, 0);
    bitmanip::toggle(u8, 0);
    EXPECT_EQ(bitmanip::check(u8, 0), !before);

    before = bitmanip::check(u8, 4);
    bitmanip::toggle(u8, 4);
    EXPECT_EQ(bitmanip::check(u8, 4), !before);

    before = bitmanip::check(u16, 15);
    bitmanip::toggle(u16, 15);
    EXPECT_EQ(bitmanip::check(u16, 15), !before);

    before = bitmanip::check(u16, 7);
    bitmanip::toggle(u16, 7);
    EXPECT_EQ(bitmanip::check(u16, 7), !before);

    before = bitmanip::check(u32, 26);
    bitmanip::toggle(u32, 26);
    EXPECT_EQ(bitmanip::check(u32, 26), !before);

    before = bitmanip::check(u32, 30);
    bitmanip::toggle(u32, 30);
    EXPECT_EQ(bitmanip::check(u32, 30), !before);

    before = bitmanip::check(u64, 62);
    bitmanip::toggle(u64, 62);
    EXPECT_EQ(bitmanip::check(u64, 62), !before);

    before = bitmanip::check(u64, 57);
    bitmanip::toggle(u64, 57);
    EXPECT_EQ(bitmanip::check(u64, 57), !before);
}

TEST(Bitman, Modify) {

    uint8_t  u8 {0b11110000};
    uint16_t u16{0b1111000011110000};
    uint32_t u32{0b11110000111100001111000011110000};
    uint64_t u64{0b1111000011110000111100001111000011110000111100001111000011110000};

    bool value;

    bitmanip::modify(u8, 0, value);
    EXPECT_EQ(bitmanip::check(u8, 0), value);

    bitmanip::modify(u8, 4, value);
    EXPECT_EQ(bitmanip::check(u8, 4), value);

    bitmanip::modify(u16, 15, value);
    EXPECT_EQ(bitmanip::check(u16, 15), value);

    bitmanip::modify(u16, 7, value);
    EXPECT_EQ(bitmanip::check(u16, 7), value);

    bitmanip::modify(u32, 26, value);
    EXPECT_EQ(bitmanip::check(u32, 26), value);

    bitmanip::modify(u32, 30, value);
    EXPECT_EQ(bitmanip::check(u32, 30), value);

    bitmanip::modify(u64, 62, value);
    EXPECT_EQ(bitmanip::check(u64, 62), value);

    bitmanip::modify(u64, 57, value);
    EXPECT_EQ(bitmanip::check(u64, 57), value);
}