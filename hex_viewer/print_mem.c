/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:11:59 by ahbasara          #+#    #+#             */
/*   Updated: 2022/10/28 20:02:14 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    print_addr(unsigned long addr, int *count, int bool)
{
    if (bool)
    {
        (*count)--;
        if (addr < 16)
        {
            while ((*count)-- > 0)
                write(1, "0", 1);
            write(1, &"0123456789abcdef"[addr % 16], 1);
        }
        if (addr > 16)
        {
            print_addr(addr / 16, count, bool);
            print_addr(addr % 16, count, bool);
        }
    }
    else
    {
        write(1, &"0123456789abcdef"[addr / 16], 1);
        write(1, &"0123456789abcdef"[addr % 16], 1);
    }
}

void    *text(long long sizec, unsigned char *x)
{
    unsigned char   *i;
    unsigned int    var;

    i = x;
    if (sizec > 16)
        var = 16;
    else
        var = sizec;
    while (x < i + var)
    {
        if (!(*x < 32 || *x > 126))
            write(1, x++, 1);
        else
        {
            write(1, ".", 1);
            x++;
        }
    }
    return (x);
}

void    *text_hex(long long sizec, unsigned char *x,
int *count)
{
    unsigned char   *i;
    int             asd;
    unsigned int    var;

    asd = 32 ;
    i = x;
    if (sizec > 16)
        var = 16;
    else
        var = sizec;
    while (x < i + var)
    {
        if (asd % 4 == 0)
            write(1, " ", 1);
        print_addr(*x++, count, 0);
        asd -= 2;
    }
    x -= var;
    asd += (asd / 4);
    while (asd-- > 0)
        write(1, " ", 1);
    write(1, " ", 1);
    return (x);
}

void    ft_print_memory(void *addr, unsigned int size)
{
    int             count;
    int             c;
    unsigned char   *x;
    long long       sizec;

    sizec = (long long) size;
    x = (unsigned char *)addr;
    c = 0;
    while (0 < sizec)
    {
        count = 16;
        print_addr((unsigned long)addr + c, &count, 1);
        write(1, ":", 1);
        x = text_hex(sizec, x, &count);
        x = text(sizec, x);
        sizec -= 16;
        c += 16;
        write(1, "\n", 1);
    }
}

int main(void)
{
    
    char asd[19000] = "Lorem ips\xffum do}*}\0lor sit a\tmeüğçt, co}\nnsectetur adipiscing elit. Pellentesque efficitur ante elementum, luctus risus quis, luctus dui. Morbi eget ultricies sem tortor.";
    
    //printf("%p\n", o);
    ft_print_memory(&asd,64);
}