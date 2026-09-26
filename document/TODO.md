SCBM-Prolog 航海日誌 ― 2026年9月26日
本日の作戦目的は、これまで np が兼任していた成功継続の生成位置と実行位置を分離し、バックトラックによる既存成功継続の消失を防ぐことだった。
従来方式では成功継続を実行するたびに np を減少させていた。このため、失敗継続から復帰した際に「どこまで成功継続が生成済みなのか」という情報と、「どこまで実行したのか」という情報が混同されていた。
そこで新たに mp を導入。mp に生成済み成功継続の境界を保持させ、成功継続を実行してもこの境界を失わない方式へ改修した。
当初レーダーは rp と np の関係を異常として捕捉したが、調査の結果、これは警戒条件の不備と判明。失敗継続と成功継続は必ずしも同じ深さになる必要はなく、単純な rp > np は異常を意味しない。
レーダーを修正して perm1([1,2,3],X) を再試験した結果、重要な観測を得た。

X = [2,3,1] ;
emergency stop by trap
TRAP: th=0 rp=9 np=0 mp=9 mode=1
back trace
0: perm1_2_1_1_end
1: perm1_2_1_1_join
2: perm1_2_1_1_path
3: perm1_2_1_1_next
4: perm1_2_1_0_join
5: perm1_2_1_0_path
6: perm1_2_1_1_end
7: perm1_2_1_1_join
8: perm1_2_1_1_path
9: select1_3_1_0_end
back_stack
0: (null)_0_0_0
1: (null)_0_0_0
2: perm1_2_1_0
3: select1_3_1_0
4: perm1_2_1_1
5: perm1_2_1_0
6: select1_3_1_0
7: perm1_2_1_1
8: perm1_2_1_0
9: perm1_2_1_1
next_stack
0: (null)_0_0_0
1: init_0_0_0
2: perm1_2_1_1
3: select1_3_1_0
4: perm1_2_1_1
5: perm1_2_1_1
6: select1_3_1_0
7: perm1_2_1_1
8: perm1_2_1_1
9: perm1_2_1_1
X = [3|v_4] ;
emergency stop by trap
TRAP: th=0 rp=4 np=0 mp=4 mode=1
back trace
0: select1_3_1_0_end
1: select1_3_1_0_join
2: select1_3_1_0_path
3: select1_3_1_0_end
4: select1_3_1_0_join
5: select1_3_1_0_back
6: perm1_2_1_1_end
7: perm1_2_1_1_join
8: perm1_2_1_1_back
9: perm1_2_1_1_next
back_stack
0: (null)_0_0_0
1: (null)_0_0_0
2: perm1_2_1_0
3: select1_3_1_0
4: select1_3_1_0
5: perm1_2_1_0
6: select1_3_1_0
7: select1_3_1_0
8: perm1_2_1_0
9: select1_3_1_0
next_stack
0: (null)_0_0_0
1: init_0_0_0
2: perm1_2_1_1
3: select1_3_1_0
4: select1_3_1_0
5: perm1_2_1_1
6: select1_3_1_0
7: select1_3_1_0
8: perm1_2_1_1
9: select1_3_1_0
no
?- halt.
- good bye -