.source hw3.j
.class public Main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 100  ; Define your storage size.
.limit locals 100 ; Define your local space number.
	ldc 0
	istore 0
L_for_conflict_0 :
ldc 0
	istore 0
L_for_begin_200 :
	ldc 10
	iload 0
	swap
	isub
	iflt L_cmp_1
	iconst_0
	goto L_cmp_0
L_cmp_1:
	iconst_1
L_cmp_0:
	ifeq L_for_exit_201
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	ldc 1
	iload 0
	iadd
	istore 0
	goto L_for_begin_200
L_for_exit_201 :
	ldc 3
	newarray int
	astore 1
	ldc 0
	aload 1
	swap
	ldc 1
	ldc 2
	iadd
	iastore
	ldc 1
	aload 1
	swap
	ldc 0
	aload 1
	swap
	ldc 1
	istore 98
	iaload
	iload 98
	isub
	iastore
	ldc 2
	aload 1
	swap
	ldc 1
	aload 1
	swap
	ldc 3
	istore 98
	iaload
	iload 98
	idiv
	iastore
	ldc 2
	aload 1
	swap
	iaload
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	ldc 3
	ldc 4
	ldc 5
	ldc 8
	ineg
	iadd
	imul
	isub
	ldc 10
	ldc 7
	idiv
	isub
	ldc 4
	ineg
	ldc 3
	irem
	isub
	ifgt L_cmp_3
	iconst_0
	goto L_cmp_2
L_cmp_3:
	iconst_1
L_cmp_2:
	iconst_1
	iconst_1
	ixor
	iconst_0
	iand
	ior
	ifne L_cmp_5
	ldc "false"
	goto L_cmp_4
L_cmp_5:
	ldc "true"
L_cmp_4:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 3
	newarray float
	astore 2
	ldc 0
	aload 2
	swap
	ldc 1.100000
	ldc 2.100000
	fadd
	fastore
	ldc 0
	aload 2
	swap
	faload
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	ldc 0
	istore 3
	ldc 2
	iload 3
	iadd
	istore 3
L_for_begin_300 :
	ldc 0
	iload 3
	swap
	isub
	ifgt L_cmp_7
	iconst_0
	goto L_cmp_6
L_cmp_7:
	iconst_1
L_cmp_6:
	ifeq L_for_exit_301
	iload 3
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 3
	ldc 1
	isub
	istore 3
	ldc 0
	iload 3
	swap
	isub
	ifne L_cmp_9
	iconst_0
	goto L_cmp_8
L_cmp_9:
	iconst_1
L_cmp_8:
	ifeq L_if_false_101
	ldc 3.140000
	fstore 4
	ldc 1.000000
	fload 4
	fadd
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	ldc "If x != "
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	fload 4
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	goto L_if_exit_100
L_if_false_101 :
	ldc 6.600000
	fstore 5
	ldc "If x == "
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	fload 5
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
L_if_exit_100 :
	ldc 0
	istore 6
L_for_conflict_0 :
ldc 1
	istore 6
L_for_begin_210 :
	ldc 3
	iload 6
	swap
	isub
	ifle L_cmp_11
	iconst_0
	goto L_cmp_10
L_cmp_11:
	iconst_1
L_cmp_10:
	ifeq L_for_exit_211
	iload 3
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "*"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 6
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "="
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 3
	iload 6
	imul
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\t"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 1
	iload 6
	iadd
	istore 6
	goto L_for_begin_210
L_for_exit_211 :
	goto L_for_begin_300
L_for_exit_301 :
	return
.end method
