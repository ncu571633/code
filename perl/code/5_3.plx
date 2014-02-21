$width = 10;
printf("%10s\n", "hello");
printf("%${width}s\n", "hello");
printf("%" . $width . "s\n", "hello");
