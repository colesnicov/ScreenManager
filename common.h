#pragma once

/**
 * File: common.h
 * Created on: 10. 9. 2017
 * Author: Denis Colesnicov <eugustus@gmail.com>
 * Version: 1.2.2
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

/**
 * Bezpecne kopirovani retezce o dane delce
 *
 * @note Pokud je zdrojovy retezec kratsi nez pocet pozadovanych znaku,
 *       zkopiruje jenom retezec o delce zdrojoveho!
 *
 * @param *dst Cilovy retezec
 * @param *src Zdrojovy retezec
 * @param size pocet znaku ke zkopirovani
 *
 * @note Zdroj: https://stackoverflow.com/a/38035721
 */
size_t strlcpy(char *dst, const char *src, size_t size)
{
    const size_t len = strlen(src);
    if (size != 0)
    {
        memcpy(dst, src, (len > size - 1) ? size - 1 : len);
        dst[size - 1] = 0;
    }
    return len;
}
