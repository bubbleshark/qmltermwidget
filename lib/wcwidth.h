#ifndef MMAP_H
#define MMAP_H



int bisearch(wchar_t ucs, const struct interval *table, int max);
int wcwidth(wchar_t ucs);
int wcswidth(const wchar_t *pwcs, size_t n);
int wcwidth_cjk(wchar_t ucs);
int wcswidth_cjk(const wchar_t *pwcs, size_t n);

#endif //MMAP_H
