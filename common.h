#pragma once

/**
 * File: common.h
 * Created on: 10. 9. 2017
 * Author: Denis Colesnicov <eugustus@gmail.com>
 * Version: 1.2.1
 */


/**
 * Vycet akci tlacitek
 */
enum Action
{
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ENTER,
    BACK
};

/**
 * Nektere procesory, napriklad attiny1634, pozaduji aby se definovala
 * tato funkce. Aby tato funkce byla viditelna pro kompilator musi se
 * definovat 'OPERATOR_DELETE'
 */
#ifdef OPERATOR_DELETE
#ifndef OPERATOR_DELETE_DEFINED
#define OPERATOR_DELETE_DEFINED

/**
 * Funkce pro uvolneni alokovane pameti
 */
void operator delete(void * p)
{
    free(p);
}

#endif
#endif

