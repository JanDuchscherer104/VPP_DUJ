//---------------------------------------------------------------------
// tst_soundex.h
// Copyright 18.09.2020
// Author: KJR
//---------------------------------------------------------------------

#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "soundex.hpp"

using namespace testing;

TEST(SoundexTest, kleinNachGross)
{
  char wort[] =    "Ananas";
  kleinNachGross(wort);
  EXPECT_EQ(strcmp(wort, "ANANAS"), 0);

}

/* TEST(SoundexTest, ZeichenCode) {
  char c0[] = "AEIOUHWY";
  char* cp = c0;
  while( *cp != '\0') {
    EXPECT_EQ(zeichenCode(*cp), '0');
    cp++;
  }

  char c1[] = "BFPV";
  cp = c1;
  while( *cp != '\0') {
    EXPECT_EQ(zeichenCode(*cp), '1');
    cp++;
  }

  char c2[] = "CGJKQSXZ";
  cp = c2;
  while( *cp != '\0') {
    EXPECT_EQ(zeichenCode(*cp), '2');
    cp++;
  }

  char c3[] = "DT";
  cp = c3;
  while ( *cp != '\0') {
    EXPECT_EQ(zeichenCode(*cp), '3');
    cp++;
  }

  EXPECT_EQ(zeichenCode('L'), '4');

  char c5[] = "MN";
  cp = c5;
  while ( *cp != '\0') {
    EXPECT_EQ(zeichenCode(*cp), '5');
    cp++;
  }

  EXPECT_EQ(zeichenCode('R'), '6');


} */

TEST(SoundexTest, WortDerLaenge1) {
  char wort[] = "d";
  char code[5] = "    ";
  soundex(wort, code);
  EXPECT_EQ(strcmp(code, "D000"), 0);
}

TEST(SoundexTest, WortUnveraendertLassen) {
  char wort[] = "d";
  char code[5] = "    ";
  soundex(wort, code);
  EXPECT_EQ(strcmp(wort, "d"), 0);
}

TEST(SoundexTest, WandeleKonsonantenInCodeZeichen) {
  char wort[] = "abcd";
  char code[5] = "    ";
  soundex(wort, code);
  EXPECT_EQ(strcmp(code, "A123"), 0);

  strncpy(wort, "bfgt", 4);
  soundex(wort, code);
  EXPECT_EQ(strcmp(code, "B123"), 0);

  strncpy(wort, "cpjl", 4);
  soundex(wort, code);
  EXPECT_EQ(strcmp(code, "C124"), 0);

  strncpy(wort, "dvkm", 4);
  soundex(wort, code);
  EXPECT_EQ(strcmp(code, "D125"), 0);

  strncpy(wort, "eqnr", 4);
  soundex(wort, code);
  EXPECT_EQ(strcmp(code, "E256"), 0);

  strncpy(wort, "Fsdx", 4);
  soundex(wort, code);
  EXPECT_EQ(strcmp(code, "F232"), 0);

  strncpy(wort, "Fzpl", 4);
  soundex(wort, code);
  EXPECT_EQ(strcmp(code, "F214"), 0);
}

TEST(SoundexTest, MaximaleLaenge4) {
  char wort[] = "abcdfgt";
  char code[5] = "    ";
  soundex(wort, code);
  EXPECT_EQ(strcmp(code, "A123"), 0);
}

TEST(SoundexTest, VokaleUndHWYalsFolgeBuchstabenIgnorieen) {
  char wort[] = "aaeiouhwybcdfgt";
  char code[5] = "    ";
  soundex(wort, code);
  EXPECT_EQ(strcmp(code, "A123"), 0);
}

TEST(SoundexTest, AufeinenderFolgendeZeichenMitGleichemCode) {
  char wort[] = "abfx";
  char code[5] = "    ";
  soundex(wort, code);
  EXPECT_EQ(strcmp(code, "A120"), 0);
}

TEST(SoundexTest, KonkreteBeispiele) {
  char wort1[] = "Britney";
  char code[5] = "    ";
  soundex(wort1, code);
  EXPECT_EQ(strcmp(code, "B635"), 0);

  char wort2[] = "Spears";
  soundex(wort2, code);
  EXPECT_EQ(strcmp(code, "S162"), 0);

  char wort3[] = "Superzicke";
  soundex(wort3, code);
  EXPECT_EQ(strcmp(code, "S162"), 0);

}
