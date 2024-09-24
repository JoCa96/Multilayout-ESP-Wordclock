#pragma once

#include "Uhrtype.hpp"

/*
 *           Layout Front
 *                COL
 *       X 9 8 7 6 5 4 3 2 1 0
 * ROW + - - - - - - - - - - -
 *  0  | E S K I S T A F Ü N F
 *  1  | Z E H N W I E N A C H
 *  2  | A N I V I E R T E L P
 *  3  | Q V O R Z G D H A L B
 *  4  | N E U N A E Z F Ü N F
 *  5  | E I N S X Ä M Z W E I
 *  6  | D R E I N U J V I E R
 *  7  | S E C H S Y L A C H T
 *  8  | S I E B E N Z W Ö L F
 *  9  | Z E H N E L F K U H R
 *
 */

class De10x11Clock_t : public iUhrType {
public:
    virtual LanguageAbbreviation usedLang() override {
        return LanguageAbbreviation::DE;
    };

    //------------------------------------------------------------------------------

    virtual const bool hasDreiviertel() override { return false; }

    //------------------------------------------------------------------------------

    void show(FrontWord word) override {
        switch (word) {

        case FrontWord::es_ist:

            setFrontMatrixWord(0, 9, 10);
            setFrontMatrixWord(0, 5, 7);
            break;

        case FrontWord::nach:
        case FrontWord::v_nach:
            setFrontMatrixWord(1, 0, 3);
            break;

        case FrontWord::vor:
        case FrontWord::v_vor:
            setFrontMatrixWord(3, 7, 9);
            break;

        case FrontWord::viertel:
            setFrontMatrixWord(2, 1, 7);
            break;

        case FrontWord::dreiviertel:
            // NOT AVAILABLE
            break;

        case FrontWord::min_5:
            setFrontMatrixWord(0, 0, 3);
            break;

        case FrontWord::min_10:
            setFrontMatrixWord(1, 7, 10);
            break;

        case FrontWord::min_20:
            setFrontMatrixWord(1, 7, 10); // zehn
            setFrontMatrixWord(3, 7, 9);  // vor
            setFrontMatrixWord(3, 0, 3);  // halb
            break;

        case FrontWord::halb:
            setFrontMatrixWord(3, 0, 3);
            break;

        case FrontWord::eins:
            setFrontMatrixWord(5, 7, 10);
            break;

        case FrontWord::uhr:
            setFrontMatrixWord(9, 0, 2);
            break;

        case FrontWord::hour_1:
            setFrontMatrixWord(6, 6, 8);
            break;

        case FrontWord::hour_2:
            setFrontMatrixWord(5, 0, 3);
            break;

        case FrontWord::hour_3:
            setFrontMatrixWord(6, 7, 10);
            break;

        case FrontWord::hour_4:
            setFrontMatrixWord(6, 0, 3);
            break;

        case FrontWord::hour_5:
            setFrontMatrixWord(4, 0, 3);
            break;

        case FrontWord::hour_6:
            setFrontMatrixWord(7, 6, 10);
            break;

        case FrontWord::hour_7:
            setFrontMatrixWord(8, 5, 10);
            break;

        case FrontWord::hour_8:
            setFrontMatrixWord(7, 0, 3);
            break;

        case FrontWord::hour_9:
            setFrontMatrixWord(9, 4, 7);
            break;

        case FrontWord::hour_10:
            setFrontMatrixWord(9, 7, 10);
            break;

        case FrontWord::hour_11:
            setFrontMatrixWord(9, 4, 6);
            break;

        case FrontWord::hour_12:
            setFrontMatrixWord(8, 0, 4);
            break;

        case FrontWord::funk:
            setFrontMatrixWord(0, 3, 3);
            setFrontMatrixWord(4, 8, 8);
            setFrontMatrixWord(4, 7, 7);
            setFrontMatrixWord(9, 3, 3);
            break;

        default:
            break;
        };
    };
};

De10x11Clock_t _de10x11Clock;