test_grep() {
 echo "Test1 $1!"
 diff -s <(grep $1 donut test_1_grep.txt) <(./s21_grep $1 donut test_1_grep.txt)
 echo " "
}

flags=("-i" "-v" "-c" "-l" "-n" "-h" "-s" "-o")

for flag in "${flags[@]}"; do
 test_grep $flag
done


echo "2Test -f 2file!"
 diff -s <(grep -f for_f_flag.txt  test_1_grep.txt test_2_grep.txt) <(./s21_grep -f for_f_flag.txt test_1_grep.txt test_2_grep.txt)
 echo " "

 echo "3Test -f 1file!"
 diff -s <(grep -f for_f_flag.txt  test_1_grep.txt ) <(./s21_grep -f for_f_flag.txt test_1_grep.txt )
 echo " "

echo "3,1Test -f 1file!"
 diff -s <(grep ./s21_grep -f for_f_flag.txt  ) <(./s21_grep ./s21_grep -f for_f_flag.txt  )
 echo " "

 echo "4Test2 -e 1_file!"
 diff -s <(grep -e donut -e coffe  test_2_grep.txt) <(./s21_grep -e donut -e coffe test_2_grep.txt)
 echo " "

 echo "5Test2 -e 2_file!"
 diff -s <(grep -e donut -e coffe test_1_grep.txt test_2_grep.txt) <(./s21_grep -e donut -e coffe test_1_grep.txt test_2_grep.txt)
 echo " "

echo "6Test2 -s!"
 diff -s <(grep -s donut notfile.txt test_1_grep.txt what.txt test_2_grep.txt) <(./s21_grep -s donut notfile.txt test_1_grep.txt what.txt test_2_grep.txt)
 echo " "

 echo "7Test2 -s noonefile!"
 diff -s <(grep -s  notfile.txt  what.txt ) <(./s21_grep -s  notfile.txt  what.txt )
 echo " "

 test_grep() {
 echo "Test2 $1!"
 diff -s <(grep $1 donut  test_1_grep.txt test_2_grep.txt) <(./s21_grep $1 donut  test_1_grep.txt test_2_grep.txt)
 echo " "
}

flags2=("-i" "-v" "-c" "-l" "-n" "-h" "-s" "-o" )

for flag2 in "${flags2[@]}"; do
 test_grep $flag2
done


