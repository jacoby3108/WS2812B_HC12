//
//  characters8x8.c    
//  Interface
//
//  Created by Sergio N. Deligiannis on 27/4/15.
//  Copyright (c) 2015 Sergio N. Deligiannis. All rights reserved.
//

#include "characters8x8.h"       

// ASCII and extended ASCII chars from 0x00 to 0xAF 
const unsigned char font8x8_basic[][8] = {
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0000 (nul)
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0001
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0002
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0003
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0004
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0005
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0006
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0007
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0008
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0009
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+000A
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+000B
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+000C
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+000D
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+000E
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+000F
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0010
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0011
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0012
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0013
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0014
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0015
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0016
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0017
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0018
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+0019
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+001A
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+001B
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+001C
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+001D
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+001E
    { 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 , 0B00000000 },   // U+001F
{
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 
},
{		// !
0B00000100 ,
0B00000100 ,
0B00000100 ,
0B00000100 ,
0B00000000 ,
0B00000000 ,
0B00000100 ,
0B00000000 
},
{		// "
0B00001010 ,
0B00001010 ,
0B00001010 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 
},
{		// #
0B00000000 ,
0B00010100 ,
0B00010100 ,
0B00111110 ,
0B00010100 ,
0B00111110 ,
0B00010100 ,
0B00010100 
},
{		// $
0B00000000 ,
0B00001000 ,
0B00011110 ,
0B00101000 ,
0B00011100 ,
0B00001010 ,
0B00111100 ,
0B00001000 
},
{		// %
0B00000000 ,
0B00110000 ,
0B00110010 ,
0B00000100 ,
0B00001000 ,
0B00010000 ,
0B00100110 ,
0B00000110 
},
{		// &
0B00000000 ,
0B00011000 ,
0B00100100 ,
0B00101000 ,
0B00010000 ,
0B00101010 ,
0B00100100 ,
0B00011010 
},
{		// '
0B00001100 ,
0B00000100 ,
0B00001000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 
},
{		// (
0B00000000 ,
0B00000010 ,
0B00000100 ,
0B00001000 ,
0B00001000 ,
0B00001000 ,
0B00000100 ,
0B00000010 
},
{		// )
0B00000000 ,
0B00001000 ,
0B00000100 ,
0B00000010 ,
0B00000010 ,
0B00000010 ,
0B00000100 ,
0B00001000 
},
{		// *
0B00000000 ,
0B00001000 ,
0B00101010 ,
0B00011100 ,
0B00101010 ,
0B00001000 ,
0B00000000 ,
0B00000000 
},
{		// +
0B00000000 ,
0B00000000 ,
0B00001000 ,
0B00001000 ,
0B00111110 ,
0B00001000 ,
0B00001000 ,
0B00000000 
},
{		// ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00001100 ,
0B00000100 ,
0B00001000 
},
{		// -
0B00000000 ,	
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00111110 ,
0B00000000 ,
0B00000000 ,
0B00000000 
},
{		// .
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00001100 ,
0B00001100 
},
{		// /
0B00000000 ,	
0B00000000 ,
0B00000010 ,
0B00000100 ,
0B00001000 ,
0B00010000 ,
0B00100000 ,
0B00000000 
},
{		// 0
0B00000000 ,	
0B00011100 ,
0B00100010 ,
0B00100110 ,
0B00101010 ,
0B00110010 ,
0B00100010 ,
0B00011100 
},
{		// 1
0B00000000 ,	
0B00000100 ,
0B00001100 ,
0B00000100 ,
0B00000100 ,
0B00000100 ,
0B00000100 ,
0B00001110 
},
{		// 2
0B00000000 ,	
0B00011100 ,
0B00100010 ,
0B00000010 ,
0B00000100 ,
0B00001000 ,
0B00010000 ,
0B00111110 
},
{		// 3
0B00000000 ,	
0B00111110 ,
0B00000100 ,
0B00001000 ,
0B00000100 ,
0B00000010 ,
0B00100010 ,
0B00011100 
},
{		// 4
0B00000000 ,	
0B00000100 ,
0B00001100 ,
0B00010100 ,
0B00100100 ,
0B00111110 ,
0B00000100 ,
0B00000100 
},
{		// 5
0B00000000 ,	
0B00111110 ,
0B00100000 ,
0B00111100 ,
0B00000010 ,
0B00000010 ,
0B00100010 ,
0B00011100 
},
{		// 6
0B00000000 ,	
0B00001100 ,
0B00010000 ,
0B00100000 ,
0B00111100 ,
0B00100010 ,
0B00100010 ,
0B00011100 
},
{		// 7
0B00000000 ,	
0B00111110 ,
0B00000010 ,
0B00000100 ,
0B00001000 ,
0B00001000 ,
0B00001000 ,
0B00001000 
},
{		// 8
0B00000000 ,	
0B00111100 ,
0B00100010 ,
0B00100010 ,
0B00011100 ,
0B00100010 ,
0B00100010 ,
0B00011100 
},
{		// 9
0B00000000 ,
0B00011100 ,
0B00100010 ,
0B00100010 ,
0B00011110 ,
0B00000010 ,
0B00000100 ,
0B00011000 
},
{		// :
0B00000000 ,
0B00000000 ,
0B00001100 ,
0B00001100 ,
0B00000000 ,
0B00001100 ,
0B00001100 ,
0B00000000 ,
},
{		// ;
0B00000000 ,	
0B00000000 ,
0B00001100 ,
0B00001100 ,
0B00000000 ,
0B00001100 ,
0B00000100 ,
0B00001000 
},
{		// <
0B00000000 ,	
0B00000010 ,
0B00000100 ,
0B00001000 ,
0B00010000 ,
0B00001000 ,
0B00000100 ,
0B00000010 ,
},
{		// =
0B00000000 ,	
0B00000000 ,
0B00000000 ,
0B00111110 ,
0B00000000 ,
0B00111110 ,
0B00000000 ,
0B00000000 
},
{		// >
0B00000000 ,	
0B00010000 ,
0B00001000 ,
0B00000100 ,
0B00000010 ,
0B00000100 ,
0B00001000 ,
0B00010000 
},
{		// ?
0B00011100 ,
0B00100010 ,
0B00000010 ,
0B00000100 ,
0B00001000 ,
0B00000000 ,
0B00001000 ,
0B00000000 
},
{		// @
0B00000000 ,	
0B00011100 ,
0B00100010 ,
0B00000010 ,
0B00011010 ,
0B00101010 ,
0B00101010 ,
0B00011100 
},
{		// A
0B00000000 ,	
0B00011100 ,
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00111110 ,
0B00100010 ,
0B00100010
},
{		// B
0B00000000 ,
0B00111100 ,
0B00010010 ,
0B00010010 ,
0B00011100 ,
0B00010010 ,
0B00010010 ,
0B00111100
},
{		// C
0B00000000 ,	
0B00011100 ,
0B00100010 ,
0B00100000 ,
0B00100000 ,
0B00100000 ,
0B00100010 ,
0B00011100
},
{		// D
0B00000000 ,
0B00111100 ,
0B00010010 ,
0B00010010 ,
0B00010010 ,
0B00010010 ,
0B00010010 ,
0B00111100
},
{		// E
0B00000000 ,	
0B00111110 ,
0B00100000 ,
0B00100000 ,
0B00111110 ,
0B00100000 ,
0B00100000 ,
0B00111110 
},
{		// F
0B00000000 ,
0B00111110 ,
0B00100000 ,
0B00100000 ,
0B00111100 ,
0B00100000 ,
0B00100000 ,
0B00100000 
},
{		// G
0B00000000 ,	
0B00011100 ,
0B00100010 ,
0B00100000 ,
0B00100110 ,
0B00100010 ,
0B00100010 ,
0B00011110 
},
{		// H
0B00000000 ,	
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00111110 ,
0B00100010 ,
0B00100010 ,
0B00100010 
},
{		// I
0B00000000 ,	
0B00011100 ,
0B00001000 ,
0B00001000 ,
0B00001000 ,
0B00001000 ,
0B00001000 ,
0B00011100 
},
{		// J
0B00000000 ,	
0B00001110 ,
0B00000100 ,
0B00000100 ,
0B00000100 ,
0B00000100 ,
0B00100100 ,
0B00011000 
},
{		// K
0B00000000 ,	
0B00100010 ,
0B00100100 ,
0B00101000 ,
0B00110000 ,
0B00101000 ,
0B00100100 ,
0B00100010 
},
{		// L
0B00000000 ,	
0B00100000 ,
0B00100000 ,
0B00100000 ,
0B00100000 ,
0B00100000 ,
0B00100000 ,
0B00111110 
},
{		// M
0B00000000 ,	
0B00100010 ,
0B00110110 ,
0B00101010 ,
0B00101010 ,
0B00100010 ,
0B00100010 ,
0B00100010 
},
{		// N
0B00000000 ,	
0B00100010 ,
0B00110010 ,
0B00110010 ,
0B00101010 ,
0B00100110 ,
0B00100110 ,
0B00100010 
},
{		// O
0B00000000 ,	
0B00011100 ,
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00011100 
},
{		// P
0B00000000 ,	
0B00111100 ,
0B00100010 ,
0B00100010 ,
0B00111100 ,
0B00100000 ,
0B00100000 ,
0B00100000 
},
{		// Q
0B00000000 ,	
0B00011100 ,
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00101010 ,
0B00100100 ,
0B00111010 
},
{		// R
0B00000000 ,
0B00111100 ,
0B00100010 ,
0B00100010 ,
0B00111100 ,
0B00101000 ,
0B00100100 ,
0B00100010 
},
{		// S
0B00000000 ,	
0B00011100 ,
0B00100010 ,
0B00100000 ,
0B00011100 ,
0B00000010 ,
0B00100010 ,
0B00011100 
},
{		// T
0B00000000 ,	
0B00111110 ,
0B00001000 ,
0B00001000 ,
0B00001000 ,
0B00001000 ,
0B00001000 ,
0B00001000 
},
{		// U
0B00000000 ,	
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00011100 
},
{		// V
0B00000000 ,	
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00010100 ,
0B00001000 
},
{		// W
0B00000000 ,	
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00101010 ,
0B00101010 ,
0B00110110 ,
0B00100010 
},
{		// X
0B00000000 ,	
0B00100010 ,
0B00100010 ,
0B00010100 ,
0B00001000 ,
0B00010100 ,
0B00100010 ,
0B00100010 
},
{		// Y
0B00000000 ,	
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00010100 ,
0B00001000 ,
0B00001000 ,
0B00001000 
},
{		// Z
0B00000000 ,	
0B00111110 ,
0B00000010 ,
0B00000100 ,
0B00001000 ,
0B00010000 ,
0B00100000 ,
0B00111110 
},
{		// [
0B000000000 ,	
0B000011100 ,
0B000010000 ,
0B000010000 ,
0B000010000 ,
0B000010000 ,
0B000010000 ,
0B000011100 
},
{		// \
0B00000000 ,	
0B00000000 ,
0B00100000 ,
0B00010000 ,
0B00001000 ,
0B00000100 ,
0B00000010 ,
0B00000000 
},
{		// ]
0B00000000 ,	
0B00001110 ,
0B00000010 ,
0B00000010 ,
0B00000010 ,
0B00000010 ,
0B00000010 ,
0B00001110 
},
{		// ^
0B00001000 ,
0B00010100 ,
0B00100010 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 
},
{		// _
0B00000000 ,	
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00111110 
},
{		// `
0B00010000 ,
0B00001000 ,
0B00000100 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 
},
{		// a
0B00000000 ,	
0B00000000 ,
0B00000000 ,
0B00011100 ,
0B00000010 ,
0B00011110 ,
0B00100010 ,
0B00011110 
},
{		// b
0B00000000 ,	
0B00100000 ,
0B00100000 ,
0B00101100 ,
0B00110010 ,
0B00100010 ,
0B00100010 ,
0B00111100 
},
{		// c
0B00000000 ,	
0B00000000 ,
0B00000000 ,
0B00011100 ,
0B00100010 ,
0B00100000 ,
0B00100010 ,
0B00011100 
},
{		// d
0B00000000 ,	
0B00000010 ,
0B00000010 ,
0B00011010 ,
0B00100110 ,
0B00100010 ,
0B00100010 ,
0B00011110 
},
{		// e
0B00000000 ,	
0B00000000 ,
0B00000000 ,
0B00011100 ,
0B00100010 ,
0B00111110 ,
0B00100000 ,
0B00011100 
},
{		// f
0B00000000 ,	
0B00000100 ,
0B00001010 ,
0B00001000 ,
0B00011100 ,
0B00001000 ,
0B00001000 ,
0B00001000 
},
{		// g
0B00000000 ,	
0B00000000 ,
0B00011010 ,
0B00100110 ,
0B00100110 ,
0B00011010 ,
0B00000010 ,
0B00011100 
},
{		// h
0B00000000 ,	
0B00100000 ,
0B00100000 ,
0B00101100 ,
0B00110010 ,
0B00100010 ,
0B00100010 ,
0B00100010 
},
{		// i
0B00000000 ,	
0B00001000 ,
0B00000000 ,
0B00011000 ,
0B00001000 ,
0B00001000 ,
0B00001000 ,
0B00011100 
},
{		// j
0B00000000 ,	
0B00000010 ,
0B00000000 ,
0B00000110 ,
0B00000010 ,
0B00000010 ,
0B00010010 ,
0B00001100 
},
{		// k
0B00000000 ,	
0B00010000 ,
0B00010000 ,
0B00010010 ,
0B00010100 ,
0B00011000 ,
0B00010100 ,
0B00010010 
},
{		// l
0B00000000 ,	
0B00001100 ,
0B00000100 ,
0B00000100 ,
0B00000100 ,
0B00000100 ,
0B00000100 ,
0B00001110 
},
{		// m
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00110100 ,
0B00101010 ,
0B00101010 ,
0B00101010 ,
0B00101010 
},
{		// n
0B00000000 ,	
0B00000000 ,
0B00000000 ,
0B00101100 ,
0B00110010 ,
0B00100010 ,
0B00100010 ,
0B00100010 
},
{		// o
0B00000000 ,	
0B00000000 ,
0B00000000 ,
0B00011100 ,
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00011100 
},
{		// p
0B00000000 ,	
0B00000000 ,
0B00101100 ,
0B00110010 ,
0B00110010 ,
0B00101100 ,
0B00100000 ,
0B00100000 
},
{		// q
0B00000000 ,	
0B00000000 ,
0B00011010 ,
0B00100110 ,
0B00100110 ,
0B00011010 ,
0B00000010 ,
0B00000010 
},
{		// r
0B00000000 ,	
0B00000000 ,
0B00000000 ,
0B00101100 ,
0B00110010 ,
0B00100000 ,
0B00100000 ,
0B00100000 
},
{		// s
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00011110 ,
0B00100000 ,
0B00111100 ,
0B00000010 ,
0B00111110 
},
{		// t
0B00000000 ,	
0B00010000 ,
0B00010000 ,
0B00111000 ,
0B00010000 ,
0B00010000 ,
0B00010010 ,
0B00001100 
},
{		// u
0B00000000 ,	
0B00000000 ,
0B00000000 ,
0B00100100 ,
0B00100100 ,
0B00100100 ,
0B00100100 ,
0B00011010 
},
{		// v
0B00000000 ,	
0B00000000 ,
0B00000000 ,
0B00100010 ,
0B00100010 ,
0B00100010 ,
0B00010100 ,
0B00001000 
},
{		// w
0B000000000 ,
0B000000000 ,
0B000000000 ,
0B000100010 ,
0B000100010 ,
0B000101010 ,
0B000101010 ,
0B000010100 
},
{		// x
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00100010 ,
0B00010100 ,
0B00001000 ,
0B00010100 ,
0B00100010 
},
{		// y
0B00000000 ,	
0B00000000 ,
0B00000000 ,
0B00100010 ,
0B00100010 ,
0B00100110 ,
0B00011010 ,
0B00000010 
},
{		// z
0B00000000 ,	
0B00000000 ,
0B00000000 ,
0B00111110 ,
0B00000100 ,
0B00001000 ,
0B00010000 ,
0B00111110 
},
{		// {
0B00000000 ,	
0B00000010 ,
0B00000100 ,
0B00000100 ,
0B00001000 ,
0B00000100 ,
0B00000100 ,
0B00000010 
},
{		// |
0B00000000 ,	
0B00000100 ,
0B00000100 ,
0B00000100 ,
0B00000000 ,
0B00000100 ,
0B00000100 ,
0B00000100 
},
{		// }
0B00000000 ,
0B00001000 ,
0B00000100 ,
0B00000100 ,
0B00000010 ,
0B00000100 ,
0B00000100 ,
0B00001000 
},
{		// ~
0B00010000 ,
0B00101010 ,
0B00000100 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 
},
{		// DEL
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 ,
0B00000000 
},
{ 	// (C cedille)
	0B01111000  ,	
	0B11001100  ,
	0B11000000  ,
	0B11001100  ,
	0B01111000  ,
	0B00011000  ,
	0B00001100  ,
	0B01111000  },
{ 	// ü
	0B00000000 ,
	0B00100100 ,
	0B00000000 ,
	0B00100100 ,
	0B00100100 ,
	0B00100100 ,
	0B00100100 ,
	0B00011010 
},	
{ 	// é
	0B00000000 ,
	0B00000111 ,
	0B00000000 ,
	0B00011100 ,
	0B00100010 ,
	0B00111110 ,
	0B00100000 ,
	0B00011100 
},	
{ 	// â
	0B00000000 ,
	0B01111110  ,	
	0B11000011  ,
	0B00111100  ,
	0B00000110  ,
	0B00111110  ,
	0B01100110  ,
	0B00111111  
},
{ 	// ä
	0B00000000 ,
	0B11001100  ,	
	0B00000000  ,
	0B01111000  ,
	0B00001100  ,
	0B01111100  ,
	0B11001100  ,
	0B01111110  
},
{ 	// à
	0B00000000 ,
	0B11100000  ,	
	0B00000000  ,
	0B01111000  ,
	0B00001100  ,
	0B01111100  ,
	0B11001100  ,
	0B01111110  
},
{ 	// (a ring)
	0B00000000 ,
	0B00110000  ,	
	0B00110000  ,
	0B01111000  ,
	0B00001100  ,
	0B01111100  ,
	0B11001100  ,
	0B01111110  
},
{  	//(c cedille)
	0B00000000  ,	
	0B00000000  ,
	0B01111000  ,
	0B11000000  ,
	0B11000000  ,
	0B01111000  ,
	0B00001100  ,
	0B00111000  },
{ 	// ê
	0B000111000 ,
	0B01111110  ,	
	0B11000011  ,
	0B00111100  ,
	0B01100110  ,
	0B01111110  ,
	0B01100000  ,
	0B00111100  
},
{ 	// ë
	0B00000000 ,
	0B11001100  ,	
	0B00000000  ,
	0B01111000  ,
	0B11001100  ,
	0B11111100  ,
	0B11000000  ,
	0B01111000  
},
{ 	// è
	0B00000000 ,
	0B11100000  ,	
	0B00000000  ,
	0B01111000  ,
	0B11001100  ,
	0B11111100  ,
	0B11000000  ,
	0B01111000  
},
{ 	// ï
	0B00000000 ,
	0B11001100  ,	
	0B00000000  ,
	0B01110000  ,
	0B00110000  ,
	0B00110000  ,
	0B00110000  ,
	0B01111000  
},
{ 	// î
	0B00011000 ,
	0B01111100  ,	
	0B11000110  ,
	0B00111000  ,
	0B00011000  ,
	0B00011000  ,
	0B00011000  ,
	0B00111100  
},
{ 	// ì
	0B00000000 	,
	0B11100000  ,	
	0B00000000  ,
	0B01110000  ,
	0B00110000  ,
	0B00110000  ,
	0B00110000  ,
	0B01111000  
},
{ 	// Ä
	0B11000110  ,	
	0B00000000 	,
	0B00111000  ,
	0B01101100  ,
	0B11000110  ,
	0B11111110  ,
	0B11000110  ,
	0B11000110  
},
{ 	// U+00C5 (A ring)
	0B00000000 	,
	0B00110000  ,	
	0B00110000  ,
	0B00000000  ,
	0B01111000  ,
	0B11001100  ,
	0B11111100  ,
	0B11001100  
},
{ 	// É
	0B00001110 ,
	0B00000000 ,
	0B00111110 ,
	0B00100000 ,
	0B00111110 ,
	0B00100000 ,
	0B00100000 ,
	0B00111110 
},
{ 	// U+00C6 (AE)
	0B00111110  ,	
	0B01101100  ,
	0B11001100  ,
	0B11111110  ,
	0B11001100  ,
	0B11001100  ,
	0B11001110  ,
	0B00000000  },
{ 	// U+00C6 (AE)
	0B00111110  ,	
	0B01101100  ,
	0B11001100  ,
	0B11111110  ,
	0B11001100  ,
	0B11001100  ,
	0B11001110  ,
	0B00000000  },	
{ 	// ô
	0B01111000  ,	
	0B11001100  ,
	0B00000000  ,
	0B01111000  ,
	0B11001100  ,
	0B11001100  ,
	0B01111000  ,
	0B00000000  },
{ 	// ö
	0B00000000 	,
	0B00000000  ,	
	0B11001100  ,
	0B00000000  ,
	0B01111000  ,
	0B11001100  ,
	0B11001100  ,
	0B01111000  
},
{ 	// ò
	0B00000000 	,
	0B00000000  ,	
	0B11100000  ,
	0B00000000  ,
	0B01111000  ,
	0B11001100  ,
	0B11001100  ,
	0B01111000  
},
{ 	// û
	0B00000000 	,
	0B01111000  , 	
	0B11001100  ,
	0B00000000  ,
	0B11001100  ,
	0B11001100  ,
	0B11001100  ,
	0B01111110  
},
{ 	// ù
	0B00000000 	,
	0B00000000  ,	
	0B11100000  ,
	0B00000000  ,
	0B11001100  ,
	0B11001100  ,
	0B11001100  ,
	0B01111110  
},
{ 	// ÿ
	0B00000000  ,	
	0B11001100  ,
	0B00000000  ,
	0B11001100  ,
	0B11001100  ,
	0B01111100  ,
	0B00001100  ,
	0B11111000  
},
{	// Ö
	0B00001110 ,
	0B00000000 ,
	0B00011100 ,
	0B00100010 ,
	0B00100010 ,
	0B00100010 ,
	0B00100010 ,
	0B00011100 
},
{ 	// Ü
	0B00000000 	,
	0B00010100 ,
	0B00100010 ,
	0B00100010 ,
	0B00100010 ,
	0B00100010 ,
	0B00100010 ,
	0B00011100 
},
{ 	// (dollarcents)
	0B00011000  ,	
	0B00011000  ,
	0B01111110  ,
	0B11000000  ,
	0B11000000  ,
	0B01111110  ,
	0B00011000  ,
	0B00011000  },
{ 	// (pound sterling)
	0B00111000  ,	
	0B01101100  ,
	0B01100100  ,
	0B11110000  ,
	0B01100000  ,
	0B11100110  ,
	0B11111100  ,
	0B00000000  },
{ 	// (yen)
	0B11001100  ,	
	0B11001100  ,
	0B01111000  ,
	0B11111100  ,
	0B00110000  ,
	0B11111100  ,
	0B00110000  ,
	0B00110000  },
{ 	// Á
	0B00001110 ,
	0B00000000 ,
	0B00011100 ,
	0B00100010 ,
	0B00100010 ,
	0B00111110 ,
	0B00100010 ,
	0B00100010 ,
},
{ 	// Í
	0B00001110 ,
	0B00000000 ,
	0B00011100 ,
	0B00001000 ,
	0B00001000 ,
	0B00001000 ,
	0B00001000 ,
	0B00011100 
},
{ 	// á
	0B00000000 ,
	0B00001110 ,	
	0B00000000 ,
	0B00011100 ,
	0B00000010 ,
	0B00011110 ,
	0B00100010 ,
	0B00011110 
},
{ 	// í
	0B00000000 ,
	0B00001110 ,
	0B00000000 ,
	0B00011000 ,
	0B00001000 ,
	0B00001000 ,
	0B00001000 ,
	0B00011100 
},
{ 	// ó
	0B00000000 ,
	0B00001110 ,
	0B00000000 ,
	0B00011100 ,
	0B00100010 ,
	0B00100010 ,
	0B00100010 ,
	0B00011100 
},
{ 	// ú
	0B00000000 ,
	0B00001110 ,
	0B00000000 ,
	0B00100100 ,
	0B00100100 ,
	0B00100100 ,
	0B00100100 ,
	0B00011010 
},	
{ 	// ñ
	0B00000000 ,
	0B00111100 ,
	0B00000000 ,
	0B00101100 ,
	0B00110010 ,
	0B00100010 ,
	0B00100010 ,
	0B00100010 
},
{ 	// Ñ
	0B00011100 ,
	0B00000000 ,
	0B00100010 ,
	0B00100010 ,
	0B00110010 ,
	0B00101010 ,
	0B00100110 ,
	0B00100010 
},
{ 	// (superscript a)
	0B00111100  ,	
	0B01101100  ,
	0B01101100  ,
	0B00111110  ,
	0B00000000  ,
	0B00000000  ,
	0B00000000  ,
	0B00000000  },
{ 	// (superscript 0)
	0B00111000  ,	
	0B01101100  ,
	0B01101100  ,
	0B00111000  ,
	0B00000000  ,
	0B00000000  ,
	0B00000000  ,
	0B00000000  },
{ 	// ¿
	0B00000000 ,
	0B00110000  ,	
	0B00000000  ,
	0B00110000  ,
	0B01100000  ,
	0B11000000  ,
	0B11001100  ,
	0B01111000  
},
{ 	// Ú
	0B00000111 ,
	0B00000000 ,
	0B00100010 ,
	0B00100010 ,
	0B00100010 ,
	0B00100010 ,
	0B00100010 ,
	0B00011100 ,
},
{ 	// ¬
	0B00000000  ,	
	0B00000000  ,
	0B00000000  ,
	0B11111100  ,
	0B00001100  ,
	0B00001100  ,
	0B00000000  ,
	0B00000000  },
{ 	// (1/2)
	0B11000011  ,	
	0B11000110  ,
	0B11001100  ,
	0B11011110  ,
	0B00110011  ,
	0B01100110  ,
	0B11001100  ,
	0B00001111  },
{ 	// (1/4)
	0B11000011  ,	
	0B11000110  ,
	0B11001100  ,
	0B10111101  ,
	0B00110111  ,
	0B01101111  ,
	0B11001111  ,
	0B11000000  },
{ 	// ¡
	0B00000000 ,
	0B00010000  ,	
	0B00010000  ,
	0B00000000  ,
	0B00010000  ,
	0B00010000  ,
	0B00010000  ,
	0B00010000  
},
{ 	// (<<)
	0B00000000  ,	
	0B00110011  ,
	0B01100110  ,
	0B11001100  ,
	0B01100110  ,
	0B00110011  ,
	0B00000000  ,
	0B00000000  },
{ 	// (>>)
	0B00000000  ,	
	0B11001100  ,
	0B01100110  ,
	0B00110011  ,
	0B01100110  ,
	0B11001100  ,
	0B00000000  ,
	0B00000000   
}};