echo "Buffer size 1 byte"
/usr/bin/time -l ./exo3-1Compiled example.txt > verifyOutput.txt
echo "Buffer size 1024 bytes"
/usr/bin/time -l ./exo3-2Compiled example.txt > verifyOutput.txt
