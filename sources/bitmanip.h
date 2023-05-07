//
// Created by halid on 07/05/2023.
//

#ifndef LOWLEVELLIBRARY_BITMANIP_H
#define LOWLEVELLIBRARY_BITMANIP_H

#include <concepts>
#include <cstdint>

#define unused(param) (void) param

namespace lll {

    // Impossible de constexpr une fonction avec un reinterpret_cast :(
    bool isBigEndian() {

        const uint16_t tmp_ = 0x1234;

        return *reinterpret_cast<const uint8_t *>(&tmp_) == 0x12;
    }

    bool isLittleEndian() {

        const uint16_t tmp_ = 0x1234;

        return *reinterpret_cast<const uint8_t *>(&tmp_) == 0x34;
    }

    namespace constraints {

        /**
         * Concept that check if the type T can be used with bitwise operands
         *
         * @tparam T type to check
         * @returns Whether T can be used with bitwise operands
         */
        template<typename T>
        concept is_bitwiseable = requires(T a, T b) {
            {~a};
            {a & b};
            {a | b};
            {a ^ b};
            {a >> b};
            {a << b};
        };
    } // namespace constraint

    namespace bitmanip {

        /**
         * Check if a bit has been set in a bitfield.
         * 
         * @tparam T1 type of the bitfield
         * @param bitfield the bitfield to check
         * @param pos the position of the bit to check
         *
         * @return Whether the bit is set
         */
        template<typename T1>
        requires constraints::is_bitwiseable<T1>
        constexpr bool check(const T1 &bitfield, const uint8_t pos) {

            return (bitfield >> pos) & static_cast<T1>(1u);
        }

        /**
         * Set a bit in a bitfield
         *
         * @tparam T1 type of the bitfield
         * @param bitfield the bitfield to set
         * @param pos the position of the bit to set
         */
        template<typename T1>
        requires constraints::is_bitwiseable<T1>
        constexpr void set(T1 &bitfield, const uint8_t pos) {

            bitfield |= static_cast<T1>(1u) << pos;

        }

        /**
         * Clear a bit in a bitfield
         *
         * @tparam T1 type of the bitfield
         * @param bitfield the bitfield to clear
         * @param pos the position of the bit to clear
         */
        template<typename T1>
        requires constraints::is_bitwiseable<T1>
        constexpr void clear(T1 &bitfield, const uint8_t pos) {

            bitfield &= ~(static_cast<T1>(1u) << pos);
        }

        /**
         * Toggle a bit in a bitfield
         *
         * @tparam T1 type of the bitfield
         * @param bitfield the bitfield to toggle
         * @param pos the position of the bit to toggle
         */
        template<typename T1>
        requires constraints::is_bitwiseable<T1>
        constexpr void toggle(T1 &bitfield, const uint8_t pos) {

            bitfield ^= static_cast<T1>(1u) << pos;
        }

        /**
         * Modify a bit in the bitfield
         *
         * @tparam T1 type of the bitfield
         * @param bitfield the bitfield to modify
         * @param pos the position of the bit to modify
         * @param value which value to give
         */
        template<typename T1>
        requires constraints::is_bitwiseable<T1>
        constexpr void modify(T1 &bitfield, const uint8_t pos, const bool value) {

            if (value) {

                set(bitfield, pos);

            } else {

                clear(bitfield, pos);

            }
        }

    } // namespace bitmanip
} // namespace lll

#endif // LOWLEVELLIBRARY_BITMANIP_H
