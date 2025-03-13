#include "draw.h"

void show_error(char *str)
{
    ssize_t	result;
    
    result = write(1, str, ft_strlen(str));
    (void)result;  // 이렇게 하면 반환 값을 사용했다고 간주합니다
    exit(1);
}