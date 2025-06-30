test_files="test_1_cat.txt test_2_cat.txt test_3_cat.txt test_4_cat.txt test_5_cat.txt test_case_cat.txt"
test_files2="test_6_cat.txt"

test_flags=("b" "ev" "n" "s" "tv" "E" "v" "e" "t" "T")
gnu_flags=("number-nonblank" "number" "squeeze-blank")

test_cat() {
 echo "Test -$1!"
 diff -s <(cat -$1 $test_files) <(./s21_cat -$1 $test_files)
 echo " "
}
test_cat2() {
 echo "Test -$1!"
 diff -s <(cat -$1 $test_files2) <(./s21_cat -$1 $test_files2)
 echo " "
}

for flag in "${gnu_flags[@]}"; do
 echo "Test -GNU: --$flag!"
 diff -s <(cat --$flag $test_files) <(./s21_cat --$flag $test_files)
 echo " "
done

for flag in "${test_flags[@]}"; do
 test_cat $flag
done

for flag in "${test_flags[@]}"; do
 test_cat2 $flag
done


diff -s <(cat -bn $test_files) <(./s21_cat -bn $test_files)
diff -s <(cat -ns $test_files) <(./s21_cat -ns $test_files)
diff -s <(cat -et $test_files) <(./s21_cat -et $test_files)
diff -s <(cat -bt $test_files) <(./s21_cat -bt $test_files)
diff -s <(cat -bns $test_files) <(./s21_cat -bns $test_files)
diff -s <(cat -etb $test_files) <(./s21_cat -etb $test_files)
diff -s <(cat -etv $test_files) <(./s21_cat -etv $test_files)
diff -s <(cat -ben $test_files) <(./s21_cat -ben $test_files)
