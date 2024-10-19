#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>
#include <linux/string.h> // For strnlen

#define MAX_LENGTH 256

SYSCALL_DEFINE1(lenfind, const char __user *, user_str)
{
    char kernel_str[MAX_LENGTH];
    int length;

    // Copy the string from user space to kernel space
    if (copy_from_user(kernel_str, user_str, MAX_LENGTH)) {
        return -EFAULT; // Return an error if copying fails
    }

    // Calculate the length of the string
    length = strnlen(kernel_str, MAX_LENGTH);

    return length; // Return the length of the string
}

