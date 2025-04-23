#include "libnvme.h"
#include "config.h"
#include <bits/fcntl-linux.h>
#include "debug.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int nvme_write(nmc_config_t config,int fd){
    int err;
    if (config.dry)
    {
        printf("dev          : ");
        print_fd_target(fd);
        pr("opcode       : 0x%02x", config.OPCODE);
        pr("nsid         : 0x%02x", config.NSID);
        pr("cdw2         : 0x%08x", config.cdw02);
        pr("cdw3         : 0x%08x", config.cdw02);
        pr("data_addr    : %p", config.data);
        pr("madata_addr  : %p", config.metadata);
        pr("data_len     : 0x%08x", config.data_len);
        pr("mdata_len    : 0x%08x", config.metadata_len);
        pr("slba         : 0x%08lx", config.slba);
        pr("nlb          : 0x%08x", config.nlb);
        pr("cdw10        : 0x%08x", config.cdw10);
        pr("cdw11        : 0x%08x", config.cdw11);
        pr("cdw12        : 0x%08x", config.cdw12);
        pr("cdw13        : 0x%08x", config.cdw13);
        pr("cdw14        : 0x%08x", config.cdw14);
        pr("cdw15        : 0x%08x", config.cdw15);
    }
    err = nvme_io_passthru(dev_fd(config.dev), config.OPCODE, config.flags, config.rsvd, config.NSID,
    config.cdw02, config.cdw03, config.cdw10, config.cdw11, config.cdw12,
    config.cdw13, config.cdw14, config.cdw15, config.data_len, config.data,
    config.metadata_len, config.metadata, config.timeout_ms, &config.result);

    if(err != 0){

    }
    else{
        
    }
}



void print_fd_target(int fd) {
    char path[64];
    char resolved_path[64];

    snprintf(path, sizeof(path), "/proc/self/fd/%d", fd);
    ssize_t len = readlink(path, resolved_path, sizeof(resolved_path) - 1);
    if (len != -1) {
        resolved_path[len] = '\0';
        printf("%s\n", fd, resolved_path);
    } else {
        perror("readlink");
    }
}

