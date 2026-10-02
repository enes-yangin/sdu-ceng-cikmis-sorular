#!/bin/bash
touch numaranigir.txt
sort $1 >> numaranigir.txt
echo 'numaranigir - İsmi Soyisim', `ls -1 | wc -l` 'dosya', $1 'dosyası' `du -b $1 | cut -f1` 'bayt', `wc -w < $1` 'kelime', `wc -m < $1` 'karakter', `wc -l < $1` 'satır'
echo $1 'dosyası' `du -b $1 | cut -f1` 'bayt', `wc -w < $1` 'kelime', `wc -m < $1` 'karakter', `wc -l < $1` 'satır' >> numaranigir.txt
chmod +r-w-x numaranigir.txt
