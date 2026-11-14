アイディアメモ

追加API
Sreplcae(x,y,th)
双方向リストのxをyに置き換える。

S_prop(x,th)
述語ｘの型を返す。
nondet,builtin,det,tailなど

フラグ call_flag 0/1
call/1はネストを禁止する

call/1 call(X)

以下のオブジェクトを生成して証明列にいれる。

Xをderefして取り出す。
nondetならcall_flagを1にしてcall_nondetにして呼び出す。
call_nondet(x,th)

call_flag == 1ならnondetオブジェクトを生成して
証明列のpcの位置を置換する。その後call_flagを０にクリア。
そのpcを生成コードは受け取って証明を続行する。

nondet以外なら
述語call_detで呼び出し、成功ならgoto success
失敗ならgoto false

