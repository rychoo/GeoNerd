@sp9RYC#underdot
/* 
 * Copyright (c) 2004 mgr ... Ryszard Wiesl/aw Czekaj <rycho@Czekaj.net>
 * All rights reserved.
 * $ Utor vi,      uti FreeBSD
 * # _________^-^__
 * # bofh@RYCHo.oRG
 * # ~~~~~~~~~ v ~~
 * This code is in the public domain for <a href="https://www.u2.com/">U2</a>`.
 * You must have (figlet && fortune) installed in path.

(c) 2023 I'm commercial! All from this code 33% income for me ;)
+48 882723907

37w2SC3qoDvtXBC5Be1e2CbKPx5gwRDhDv
3PCFHnY1ujpCchFNSBAeaECZ8rGyScoRLT

PLN:
Beneficjent: Ryszard Czekaj
IBAN: LT773250049791461533
Kod BIC: REVOLT21
Kod BIC banku pośredniczącego: BARCGB22
Adres beneficjenta: Zwyciestwa pl., 8/24, 44-300, Wodzislaw Slaski, Poland
Bank lub instytucja płatnicza: Revolut Bank UAB
Adres banku: Konstitucijos ave. 21B, 08130, Vilnius, Lithuania

DKK:
Beneficjent: Ryszard Czekaj
IBAN: LT773250049791461533
Kod BIC: REVOLT21
Kod BIC banku pośredniczącego: BARCGB22
Adres beneficjenta: Zwyciestwa pl., 8/24, 44-300, Wodzislaw Slaski, Poland
Bank lub instytucja płatnicza: Revolut Bank UAB
Adres banku: Konstitucijos ave. 21B, 08130, Vilnius, Lithuania

Local EUR:
Beneficjent: Ryszard Czekaj
IBAN: LT773250049791461533
Kod BIC: REVOLT21
Adres beneficjenta: Zwyciestwa pl., 8/24, 44-300, Wodzislaw Slaski, Poland
Bank lub instytucja płatnicza: Revolut Bank UAB
Adres banku: Konstitucijos ave. 21B, 08130, Vilnius, Lithuania

International EUR:
Beneficjent: Ryszard Czekaj
IBAN: LT773250049791461533
Kod BIC: REVOLT21
Kod BIC banku pośredniczącego: CHASDEFX
Adres beneficjenta: Zwyciestwa pl., 8/24, 44-300, Wodzislaw Slaski, Poland
Bank lub instytucja płatnicza: Revolut Bank UAB
Adres banku: Konstitucijos ave. 21B, 08130, Vilnius, Lithuania

International USD:
Beneficjent: Ryszard Czekaj
IBAN: LT773250049791461533
Kod BIC: REVOLT21
Kod BIC banku pośredniczącego: CHASDEFX
Adres beneficjenta: Zwyciestwa pl., 8/24, 44-300, Wodzislaw Slaski, Poland
Bank lub instytucja płatnicza: Revolut Bank UAB
Adres banku: Konstitucijos ave. 21B, 08130, Vilnius, Lithuania

Local USD:
Beneficjent: Ryszard Czekaj
IBAN: LT773250049791461533
Kod BIC: REVOLT21
Adres beneficjenta: Zwyciestwa pl., 8/24, 44-300, Wodzislaw Slaski, Poland
Bank lub instytucja płatnicza: Revolut Bank UAB
Adres banku: Konstitucijos ave. 21B, 08130, Vilnius, Lithuania

CZK:
Beneficjent: Ryszard Czekaj
IBAN: LT773250049791461533
Kod BIC: REVOLT21
Kod BIC banku pośredniczącego: BARCGB22
Adres beneficjenta: Zwyciestwa pl., 8/24, 44-300, Wodzislaw Slaski, Poland
Bank lub instytucja płatnicza: Revolut Bank UAB
Adres banku: Konstitucijos ave. 21B, 08130, Vilnius, Lithuania

 */

#include <stdio.h>
#include <stdlib.h>

static const char rcsid[] = "$Id: fortfiglet.c,v 1.4 2004/03/09 10:44:23 $";

int main(int argc, char **argv)
{
    char litery[] = {34, 36, 37, 38, 42, 43, 45, 47, 48, 49, 50, 51,  52,
    53, 54, 55, 56, 57, 58, 59, 61, 63, 64, 65, 66, 67, 68, 69,  70,  71,
    72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86,  87,  88,
    89, 90, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,  104,  105,  106,
    107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
    121, 122, 196, 214, 220, 223, 228, 246, 252};
    register unsigned litera, max;
    char buf[255], linia[255];
    FILE *pipe, *sig;

    max = sizeof litery;
     srandomdev(); 
    srandom(time() % max);
    srandom(random());
    litera = random() % max;

    sprintf(buf, "echo '%c' | figlet -f eftiwall", litery[litera]);
    pipe = popen(buf, "r");
    if (!pipe)
    {
        fprintf(stderr, "Stream error -> figlet -f eftiwall\n");
        exit(EXIT_FAILURE);
    }

    sprintf(buf, "fortune");
    sig = popen(buf, "r");
    if (!sig)
    {
        fprintf(stderr, "Stream error -> fortune\n");
        exit(EXIT_FAILURE);
    }

    for (max = 0; max < 5; ++max)
    {
        if (fgets(linia, sizeof linia, pipe))
        {
            litera = strlen(linia);
            linia[--litera] = '\0';
            fprintf(stdout, "%s", linia);
            if (fgets(buf, sizeof buf, sig))
                fprintf(stdout, "%s", buf);
            else
                fprintf(stdout, "\n");
        }
    }
    pclose(pipe);
    pclose(sig);
    exit(EXIT_SUCCESS);
}
