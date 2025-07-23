; ModuleID = '123'
source_filename = "123"

@map = common global [100 x i32]
@wall = dso_local global i32 35
@air = dso_local global i32 32
@newLine = dso_local global i32 10
@pl = dso_local global i32 60
@pr = dso_local global i32 62
@pu = dso_local global i32 94
@pd = dso_local global i32 118
@deadChar = dso_local global i32 88
@pdir = dso_local global i32 0
@px = dso_local global i32 1
@py = dso_local global i32 1
@bChar = dso_local global i32 79
@bdir = dso_local global i32 10
@bx = dso_local global i32 0
@by = dso_local global i32 0
@monsterChar = dso_local global i32 87
@mx = common global [5 x i32]
@my = common global [5 x i32]
@mAlive = common global [5 x i32]
@mdir = common global [5 x i32]
@mpath = common global [5 x i32]
@mChange = common global [5 x i32]
@stepCounter = dso_local global i32 0
@done = dso_local global i32 0
@dead = dso_local global i32 0
@won = dso_local global i32 0
@0 = private unnamed_addr constant [80 x i8] c"\221- turn left, 2- move forward, 3- turn right, 0- shoot, 99- exit, other- wait\22\00", align 1
@1 = private unnamed_addr constant [11 x i8] c"\22You Won!\22\00", align 1
@2 = private unnamed_addr constant [14 x i8] c"\22You Lost :(\22\00", align 1

declare i32 @in()

declare void @outChar(i32)

declare void @print(i8*)

define i32 @getValue(i32 %0, i32 %1) {
entry:
  %r = alloca i32, align 4
  store i32 %0, i32* %r, align 4
  %c = alloca i32, align 4
  store i32 %1, i32* %c, align 4
  %i = alloca i32, align 4
  %r1 = load i32, i32* %r, align 4
  %2 = mul nsw i32 %r1, 10
  %c2 = load i32, i32* %c, align 4
  %3 = add nsw i32 %2, %c2
  store i32 %3, i32* %i, align 4
  %i3 = load i32, i32* %i, align 4
  %4 = getelementptr [100 x i32], [100 x i32]* @map, i32 0, i32 %i3
  %5 = load i32, i32* %4, align 4
  ret i32 %5
}

define void @setValue(i32 %0, i32 %1, i32 %2) {
entry:
  %r = alloca i32, align 4
  store i32 %0, i32* %r, align 4
  %c = alloca i32, align 4
  store i32 %1, i32* %c, align 4
  %v = alloca i32, align 4
  store i32 %2, i32* %v, align 4
  %i = alloca i32, align 4
  %r1 = load i32, i32* %r, align 4
  %3 = mul nsw i32 %r1, 10
  %c2 = load i32, i32* %c, align 4
  %4 = add nsw i32 %3, %c2
  store i32 %4, i32* %i, align 4
  %i3 = load i32, i32* %i, align 4
  %5 = getelementptr [100 x i32], [100 x i32]* @map, i32 0, i32 %i3
  %6 = load i32, i32* %5, align 4
  %v4 = load i32, i32* %v, align 4
  store i32 %v4, i32* %5, align 4
  ret void
}

define i32 @roundAdd(i32 %0) {
entry:
  %dir = alloca i32, align 4
  store i32 %0, i32* %dir, align 4
  %dir1 = load i32, i32* %dir, align 4
  %1 = icmp eq i32 %dir1, 3
  %2 = zext i1 %1 to i32
  %3 = trunc i32 %2 to i1
  br i1 %3, label %bTrue, label %bContinue

bTrue:                                            ; preds = %entry
  ret i32 0
  br label %bContinue

bContinue:                                        ; preds = %bTrue, %entry
  %dir2 = load i32, i32* %dir, align 4
  %4 = add nsw i32 %dir2, 1
  ret i32 %4
}

define i32 @roundSub(i32 %0) {
entry:
  %dir = alloca i32, align 4
  store i32 %0, i32* %dir, align 4
  %dir1 = load i32, i32* %dir, align 4
  %1 = icmp eq i32 %dir1, 0
  %2 = zext i1 %1 to i32
  %3 = trunc i32 %2 to i1
  br i1 %3, label %bTrue, label %bContinue

bTrue:                                            ; preds = %entry
  ret i32 3
  br label %bContinue

bContinue:                                        ; preds = %bTrue, %entry
  %dir2 = load i32, i32* %dir, align 4
  %4 = sub nsw i32 %dir2, 1
  ret i32 %4
}

define i32 @hasMonster(i32 %0, i32 %1) {
entry:
  %x = alloca i32, align 4
  store i32 %0, i32* %x, align 4
  %y = alloca i32, align 4
  store i32 %1, i32* %y, align 4
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %i1 = load i32, i32* %i, align 4
  %2 = icmp slt i32 %i1, 5
  %3 = zext i1 %2 to i32
  %4 = trunc i32 %3 to i1
  br i1 %4, label %lTrue, label %lContinue

lTrue:                                            ; preds = %bContinue, %entry
  %i2 = load i32, i32* %i, align 4
  %5 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 %i2
  %6 = load i32, i32* %5, align 4
  %x3 = load i32, i32* %x, align 4
  %7 = icmp eq i32 %6, %x3
  %8 = zext i1 %7 to i32
  %i4 = load i32, i32* %i, align 4
  %9 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 %i4
  %10 = load i32, i32* %9, align 4
  %y5 = load i32, i32* %y, align 4
  %11 = icmp eq i32 %10, %y5
  %12 = zext i1 %11 to i32
  %13 = trunc i32 %8 to i1
  %14 = trunc i32 %12 to i1
  %15 = and i1 %13, %14
  %16 = zext i1 %15 to i32
  %i6 = load i32, i32* %i, align 4
  %17 = getelementptr [5 x i32], [5 x i32]* @mAlive, i32 0, i32 %i6
  %18 = load i32, i32* %17, align 4
  %19 = trunc i32 %16 to i1
  %20 = trunc i32 %18 to i1
  %21 = and i1 %19, %20
  %22 = zext i1 %21 to i32
  %23 = trunc i32 %22 to i1
  br i1 %23, label %bTrue, label %bContinue

lContinue:                                        ; preds = %bContinue, %entry
  ret i32 0

bTrue:                                            ; preds = %lTrue
  ret i32 1
  br label %bContinue

bContinue:                                        ; preds = %bTrue, %lTrue
  %i7 = load i32, i32* %i, align 4
  %24 = add nsw i32 %i7, 1
  store i32 %24, i32* %i, align 4
  %i8 = load i32, i32* %i, align 4
  %25 = icmp slt i32 %i8, 5
  %26 = zext i1 %25 to i32
  %27 = trunc i32 %26 to i1
  br i1 %27, label %lTrue, label %lContinue
}

define void @makeMap() {
entry:
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %i1 = load i32, i32* %i, align 4
  %0 = icmp slt i32 %i1, 10
  %1 = zext i1 %0 to i32
  %2 = trunc i32 %1 to i1
  br i1 %2, label %lTrue, label %lContinue

lTrue:                                            ; preds = %lTrue, %entry
  %i2 = load i32, i32* %i, align 4
  %wall = load i32, i32* @wall, align 4
  call void @setValue(i32 %i2, i32 0, i32 %wall)
  %i3 = load i32, i32* %i, align 4
  %wall4 = load i32, i32* @wall, align 4
  call void @setValue(i32 %i3, i32 9, i32 %wall4)
  %i5 = load i32, i32* %i, align 4
  %wall6 = load i32, i32* @wall, align 4
  call void @setValue(i32 9, i32 %i5, i32 %wall6)
  %i7 = load i32, i32* %i, align 4
  %wall8 = load i32, i32* @wall, align 4
  call void @setValue(i32 0, i32 %i7, i32 %wall8)
  %i9 = load i32, i32* %i, align 4
  %3 = add nsw i32 %i9, 1
  store i32 %3, i32* %i, align 4
  %i10 = load i32, i32* %i, align 4
  %4 = icmp slt i32 %i10, 10
  %5 = zext i1 %4 to i32
  %6 = trunc i32 %5 to i1
  br i1 %6, label %lTrue, label %lContinue

lContinue:                                        ; preds = %lTrue, %entry
  store i32 1, i32* %i, align 4
  %i13 = load i32, i32* %i, align 4
  %7 = icmp slt i32 %i13, 9
  %8 = zext i1 %7 to i32
  %9 = trunc i32 %8 to i1
  br i1 %9, label %lTrue11, label %lContinue12

lTrue11:                                          ; preds = %lContinue15, %lContinue
  %j = alloca i32, align 4
  store i32 1, i32* %j, align 4
  %j16 = load i32, i32* %j, align 4
  %10 = icmp slt i32 %j16, 9
  %11 = zext i1 %10 to i32
  %12 = trunc i32 %11 to i1
  br i1 %12, label %lTrue14, label %lContinue15

lContinue12:                                      ; preds = %lContinue15, %lContinue
  %wall23 = load i32, i32* @wall, align 4
  call void @setValue(i32 1, i32 4, i32 %wall23)
  %wall24 = load i32, i32* @wall, align 4
  call void @setValue(i32 1, i32 5, i32 %wall24)
  %wall25 = load i32, i32* @wall, align 4
  call void @setValue(i32 2, i32 2, i32 %wall25)
  %wall26 = load i32, i32* @wall, align 4
  call void @setValue(i32 2, i32 7, i32 %wall26)
  %wall27 = load i32, i32* @wall, align 4
  call void @setValue(i32 3, i32 4, i32 %wall27)
  %wall28 = load i32, i32* @wall, align 4
  call void @setValue(i32 3, i32 5, i32 %wall28)
  %wall29 = load i32, i32* @wall, align 4
  call void @setValue(i32 3, i32 7, i32 %wall29)
  %wall30 = load i32, i32* @wall, align 4
  call void @setValue(i32 4, i32 1, i32 %wall30)
  %wall31 = load i32, i32* @wall, align 4
  call void @setValue(i32 4, i32 2, i32 %wall31)
  %wall32 = load i32, i32* @wall, align 4
  call void @setValue(i32 5, i32 1, i32 %wall32)
  %wall33 = load i32, i32* @wall, align 4
  call void @setValue(i32 5, i32 2, i32 %wall33)
  %wall34 = load i32, i32* @wall, align 4
  call void @setValue(i32 5, i32 4, i32 %wall34)
  %wall35 = load i32, i32* @wall, align 4
  call void @setValue(i32 5, i32 5, i32 %wall35)
  %wall36 = load i32, i32* @wall, align 4
  call void @setValue(i32 5, i32 6, i32 %wall36)
  %wall37 = load i32, i32* @wall, align 4
  call void @setValue(i32 5, i32 8, i32 %wall37)
  %wall38 = load i32, i32* @wall, align 4
  call void @setValue(i32 6, i32 5, i32 %wall38)
  %wall39 = load i32, i32* @wall, align 4
  call void @setValue(i32 7, i32 2, i32 %wall39)
  %wall40 = load i32, i32* @wall, align 4
  call void @setValue(i32 7, i32 3, i32 %wall40)
  %wall41 = load i32, i32* @wall, align 4
  call void @setValue(i32 7, i32 7, i32 %wall41)
  %wall42 = load i32, i32* @wall, align 4
  call void @setValue(i32 8, i32 5, i32 %wall42)
  ret void

lTrue14:                                          ; preds = %lTrue14, %lTrue11
  %i17 = load i32, i32* %i, align 4
  %j18 = load i32, i32* %j, align 4
  %air = load i32, i32* @air, align 4
  call void @setValue(i32 %i17, i32 %j18, i32 %air)
  %j19 = load i32, i32* %j, align 4
  %13 = add nsw i32 %j19, 1
  store i32 %13, i32* %j, align 4
  %j20 = load i32, i32* %j, align 4
  %14 = icmp slt i32 %j20, 9
  %15 = zext i1 %14 to i32
  %16 = trunc i32 %15 to i1
  br i1 %16, label %lTrue14, label %lContinue15

lContinue15:                                      ; preds = %lTrue14, %lTrue11
  %i21 = load i32, i32* %i, align 4
  %17 = add nsw i32 %i21, 1
  store i32 %17, i32* %i, align 4
  %i22 = load i32, i32* %i, align 4
  %18 = icmp slt i32 %i22, 9
  %19 = zext i1 %18 to i32
  %20 = trunc i32 %19 to i1
  br i1 %20, label %lTrue11, label %lContinue12
}

define void @makeMonsters() {
entry:
  %0 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 0
  %1 = load i32, i32* %0, align 4
  store i32 8, i32* %0, align 4
  %2 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 0
  %3 = load i32, i32* %2, align 4
  store i32 8, i32* %2, align 4
  %4 = getelementptr [5 x i32], [5 x i32]* @mAlive, i32 0, i32 0
  %5 = load i32, i32* %4, align 4
  store i32 1, i32* %4, align 4
  %6 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 0
  %7 = load i32, i32* %6, align 4
  store i32 3, i32* %6, align 4
  %8 = getelementptr [5 x i32], [5 x i32]* @mpath, i32 0, i32 0
  %9 = load i32, i32* %8, align 4
  store i32 0, i32* %8, align 4
  %10 = getelementptr [5 x i32], [5 x i32]* @mChange, i32 0, i32 0
  %11 = load i32, i32* %10, align 4
  store i32 20, i32* %10, align 4
  %12 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 1
  %13 = load i32, i32* %12, align 4
  store i32 7, i32* %12, align 4
  %14 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 1
  %15 = load i32, i32* %14, align 4
  store i32 5, i32* %14, align 4
  %16 = getelementptr [5 x i32], [5 x i32]* @mAlive, i32 0, i32 1
  %17 = load i32, i32* %16, align 4
  store i32 1, i32* %16, align 4
  %18 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 1
  %19 = load i32, i32* %18, align 4
  store i32 1, i32* %18, align 4
  %20 = getelementptr [5 x i32], [5 x i32]* @mpath, i32 0, i32 1
  %21 = load i32, i32* %20, align 4
  store i32 0, i32* %20, align 4
  %22 = getelementptr [5 x i32], [5 x i32]* @mChange, i32 0, i32 1
  %23 = load i32, i32* %22, align 4
  store i32 3, i32* %22, align 4
  %24 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 2
  %25 = load i32, i32* %24, align 4
  store i32 4, i32* %24, align 4
  %26 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 2
  %27 = load i32, i32* %26, align 4
  store i32 7, i32* %26, align 4
  %28 = getelementptr [5 x i32], [5 x i32]* @mAlive, i32 0, i32 2
  %29 = load i32, i32* %28, align 4
  store i32 1, i32* %28, align 4
  %30 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 2
  %31 = load i32, i32* %30, align 4
  store i32 2, i32* %30, align 4
  %32 = getelementptr [5 x i32], [5 x i32]* @mpath, i32 0, i32 2
  %33 = load i32, i32* %32, align 4
  store i32 1, i32* %32, align 4
  %34 = getelementptr [5 x i32], [5 x i32]* @mChange, i32 0, i32 2
  %35 = load i32, i32* %34, align 4
  store i32 4, i32* %34, align 4
  %36 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 3
  %37 = load i32, i32* %36, align 4
  store i32 8, i32* %36, align 4
  %38 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 3
  %39 = load i32, i32* %38, align 4
  store i32 2, i32* %38, align 4
  %40 = getelementptr [5 x i32], [5 x i32]* @mAlive, i32 0, i32 3
  %41 = load i32, i32* %40, align 4
  store i32 1, i32* %40, align 4
  %42 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 3
  %43 = load i32, i32* %42, align 4
  store i32 3, i32* %42, align 4
  %44 = getelementptr [5 x i32], [5 x i32]* @mpath, i32 0, i32 3
  %45 = load i32, i32* %44, align 4
  store i32 0, i32* %44, align 4
  %46 = getelementptr [5 x i32], [5 x i32]* @mChange, i32 0, i32 3
  %47 = load i32, i32* %46, align 4
  store i32 5, i32* %46, align 4
  %48 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 4
  %49 = load i32, i32* %48, align 4
  store i32 1, i32* %48, align 4
  %50 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 4
  %51 = load i32, i32* %50, align 4
  store i32 8, i32* %50, align 4
  %52 = getelementptr [5 x i32], [5 x i32]* @mAlive, i32 0, i32 4
  %53 = load i32, i32* %52, align 4
  store i32 1, i32* %52, align 4
  %54 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 4
  %55 = load i32, i32* %54, align 4
  store i32 0, i32* %54, align 4
  %56 = getelementptr [5 x i32], [5 x i32]* @mpath, i32 0, i32 4
  %57 = load i32, i32* %56, align 4
  store i32 0, i32* %56, align 4
  %58 = getelementptr [5 x i32], [5 x i32]* @mChange, i32 0, i32 4
  %59 = load i32, i32* %58, align 4
  store i32 7, i32* %58, align 4
  ret void
}

define i32 @printMonster(i32 %0, i32 %1) {
entry:
  %x = alloca i32, align 4
  store i32 %0, i32* %x, align 4
  %y = alloca i32, align 4
  store i32 %1, i32* %y, align 4
  %x1 = load i32, i32* %x, align 4
  %y2 = load i32, i32* %y, align 4
  %2 = call i32 @hasMonster(i32 %x1, i32 %y2)
  %3 = trunc i32 %2 to i1
  br i1 %3, label %bTrue, label %bContinue

bTrue:                                            ; preds = %entry
  %monsterChar = load i32, i32* @monsterChar, align 4
  call void @outChar(i32 %monsterChar)
  ret i32 1
  br label %bContinue

bContinue:                                        ; preds = %bTrue, %entry
  ret i32 0
}

define void @printPlayer() {
entry:
  %dead = load i32, i32* @dead, align 4
  %0 = trunc i32 %dead to i1
  br i1 %0, label %bTrue, label %bContinue

bTrue:                                            ; preds = %entry
  %deadChar = load i32, i32* @deadChar, align 4
  call void @outChar(i32 %deadChar)
  ret void
  br label %bContinue

bContinue:                                        ; preds = %bTrue, %entry
  %pdir = load i32, i32* @pdir, align 4
  %1 = icmp eq i32 %pdir, 0
  %2 = zext i1 %1 to i32
  %3 = trunc i32 %2 to i1
  br i1 %3, label %SelectPt0, label %FSelectPt0

SelectPt0:                                        ; preds = %bContinue
  %pd = load i32, i32* @pd, align 4
  call void @outChar(i32 %pd)
  br label %bContinue1

FSelectPt0:                                       ; preds = %bContinue
  %pdir2 = load i32, i32* @pdir, align 4
  %4 = icmp eq i32 %pdir2, 1
  %5 = zext i1 %4 to i32
  %6 = trunc i32 %5 to i1
  br i1 %6, label %SelectPt1, label %FSelectPt1

SelectPt1:                                        ; preds = %FSelectPt0
  %pl = load i32, i32* @pl, align 4
  call void @outChar(i32 %pl)
  br label %bContinue1

FSelectPt1:                                       ; preds = %FSelectPt0
  %pdir3 = load i32, i32* @pdir, align 4
  %7 = icmp eq i32 %pdir3, 2
  %8 = zext i1 %7 to i32
  %9 = trunc i32 %8 to i1
  br i1 %9, label %SelectPt2, label %FSelectPt2

SelectPt2:                                        ; preds = %FSelectPt1
  %pu = load i32, i32* @pu, align 4
  call void @outChar(i32 %pu)
  br label %bContinue1

FSelectPt2:                                       ; preds = %FSelectPt1
  %pdir4 = load i32, i32* @pdir, align 4
  %10 = icmp eq i32 %pdir4, 3
  %11 = zext i1 %10 to i32
  %12 = trunc i32 %11 to i1
  br i1 %12, label %SelectPt3, label %FSelectPt3

SelectPt3:                                        ; preds = %FSelectPt2
  %pr = load i32, i32* @pr, align 4
  call void @outChar(i32 %pr)
  br label %bContinue1

FSelectPt3:                                       ; preds = %FSelectPt2
  br label %bContinue1

bContinue1:                                       ; preds = %FSelectPt3, %SelectPt3, %SelectPt2, %SelectPt1, %SelectPt0
  ret void
}

define void @printMap() {
entry:
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %i1 = load i32, i32* %i, align 4
  %0 = icmp slt i32 %i1, 10
  %1 = zext i1 %0 to i32
  %2 = trunc i32 %1 to i1
  br i1 %2, label %lTrue, label %lContinue

lTrue:                                            ; preds = %lContinue3, %entry
  %j = alloca i32, align 4
  store i32 0, i32* %j, align 4
  %j4 = load i32, i32* %j, align 4
  %3 = icmp slt i32 %j4, 10
  %4 = zext i1 %3 to i32
  %5 = trunc i32 %4 to i1
  br i1 %5, label %lTrue2, label %lContinue3

lContinue:                                        ; preds = %lContinue3, %entry
  ret void

lTrue2:                                           ; preds = %bContinue, %lTrue
  %j5 = load i32, i32* %j, align 4
  %i6 = load i32, i32* %i, align 4
  %6 = call i32 @printMonster(i32 %j5, i32 %i6)
  %7 = trunc i32 %6 to i1
  %8 = xor i1 %7, true
  %9 = zext i1 %8 to i32
  %10 = trunc i32 %9 to i1
  br i1 %10, label %bTrue, label %bContinue

lContinue3:                                       ; preds = %bContinue, %lTrue
  %newLine = load i32, i32* @newLine, align 4
  call void @outChar(i32 %newLine)
  %i21 = load i32, i32* %i, align 4
  %11 = add nsw i32 %i21, 1
  store i32 %11, i32* %i, align 4
  %i22 = load i32, i32* %i, align 4
  %12 = icmp slt i32 %i22, 10
  %13 = zext i1 %12 to i32
  %14 = trunc i32 %13 to i1
  br i1 %14, label %lTrue, label %lContinue

bTrue:                                            ; preds = %lTrue2
  %px = load i32, i32* @px, align 4
  %j9 = load i32, i32* %j, align 4
  %15 = icmp eq i32 %px, %j9
  %16 = zext i1 %15 to i32
  %py = load i32, i32* @py, align 4
  %i10 = load i32, i32* %i, align 4
  %17 = icmp eq i32 %py, %i10
  %18 = zext i1 %17 to i32
  %19 = trunc i32 %16 to i1
  %20 = trunc i32 %18 to i1
  %21 = and i1 %19, %20
  %22 = zext i1 %21 to i32
  %23 = trunc i32 %22 to i1
  br i1 %23, label %bTrue7, label %bFalse

bContinue:                                        ; preds = %bContinue8, %lTrue2
  %j19 = load i32, i32* %j, align 4
  %24 = add nsw i32 %j19, 1
  store i32 %24, i32* %j, align 4
  %j20 = load i32, i32* %j, align 4
  %25 = icmp slt i32 %j20, 10
  %26 = zext i1 %25 to i32
  %27 = trunc i32 %26 to i1
  br i1 %27, label %lTrue2, label %lContinue3

bTrue7:                                           ; preds = %bTrue
  call void @printPlayer()
  br label %bContinue8

bFalse:                                           ; preds = %bTrue
  %bdir = load i32, i32* @bdir, align 4
  %28 = icmp ne i32 %bdir, 10
  %29 = zext i1 %28 to i32
  %bx = load i32, i32* @bx, align 4
  %j14 = load i32, i32* %j, align 4
  %30 = icmp eq i32 %bx, %j14
  %31 = zext i1 %30 to i32
  %32 = trunc i32 %29 to i1
  %33 = trunc i32 %31 to i1
  %34 = and i1 %32, %33
  %35 = zext i1 %34 to i32
  %by = load i32, i32* @by, align 4
  %i15 = load i32, i32* %i, align 4
  %36 = icmp eq i32 %by, %i15
  %37 = zext i1 %36 to i32
  %38 = trunc i32 %35 to i1
  %39 = trunc i32 %37 to i1
  %40 = and i1 %38, %39
  %41 = zext i1 %40 to i32
  %42 = trunc i32 %41 to i1
  br i1 %42, label %bTrue11, label %bFalse12

bContinue8:                                       ; preds = %bContinue13, %bTrue7
  br label %bContinue

bTrue11:                                          ; preds = %bFalse
  %bChar = load i32, i32* @bChar, align 4
  call void @outChar(i32 %bChar)
  br label %bContinue13

bFalse12:                                         ; preds = %bFalse
  %v = alloca i32, align 4
  %j16 = load i32, i32* %j, align 4
  %i17 = load i32, i32* %i, align 4
  %43 = call i32 @getValue(i32 %j16, i32 %i17)
  store i32 %43, i32* %v, align 4
  %v18 = load i32, i32* %v, align 4
  call void @outChar(i32 %v18)
  br label %bContinue13

bContinue13:                                      ; preds = %bFalse12, %bTrue11
  br label %bContinue8
}

define i32 @tryMove(i32 %0, i32 %1) {
entry:
  %i = alloca i32, align 4
  store i32 %0, i32* %i, align 4
  %dir = alloca i32, align 4
  store i32 %1, i32* %dir, align 4
  %dir1 = load i32, i32* %dir, align 4
  %2 = icmp eq i32 %dir1, 3
  %3 = zext i1 %2 to i32
  %4 = trunc i32 %3 to i1
  br i1 %4, label %bTrue, label %bContinue

bTrue:                                            ; preds = %entry
  %i4 = load i32, i32* %i, align 4
  %5 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 %i4
  %6 = load i32, i32* %5, align 4
  %7 = add nsw i32 %6, 1
  %i5 = load i32, i32* %i, align 4
  %8 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 %i5
  %9 = load i32, i32* %8, align 4
  %10 = call i32 @getValue(i32 %7, i32 %9)
  %air = load i32, i32* @air, align 4
  %11 = icmp eq i32 %10, %air
  %12 = zext i1 %11 to i32
  %i6 = load i32, i32* %i, align 4
  %13 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 %i6
  %14 = load i32, i32* %13, align 4
  %15 = add nsw i32 %14, 1
  %i7 = load i32, i32* %i, align 4
  %16 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 %i7
  %17 = load i32, i32* %16, align 4
  %18 = call i32 @hasMonster(i32 %15, i32 %17)
  %19 = trunc i32 %18 to i1
  %20 = xor i1 %19, true
  %21 = zext i1 %20 to i32
  %22 = trunc i32 %12 to i1
  %23 = trunc i32 %21 to i1
  %24 = and i1 %22, %23
  %25 = zext i1 %24 to i32
  %26 = trunc i32 %25 to i1
  br i1 %26, label %bTrue2, label %bContinue3

bContinue:                                        ; preds = %bContinue3, %entry
  %dir12 = load i32, i32* %dir, align 4
  %27 = icmp eq i32 %dir12, 2
  %28 = zext i1 %27 to i32
  %29 = trunc i32 %28 to i1
  br i1 %29, label %bTrue10, label %bContinue11

bTrue2:                                           ; preds = %bTrue
  %i8 = load i32, i32* %i, align 4
  %30 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 %i8
  %31 = load i32, i32* %30, align 4
  %i9 = load i32, i32* %i, align 4
  %32 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 %i9
  %33 = load i32, i32* %32, align 4
  %34 = add nsw i32 %33, 1
  store i32 %34, i32* %30, align 4
  ret i32 1
  br label %bContinue3

bContinue3:                                       ; preds = %bTrue2, %bTrue
  br label %bContinue

bTrue10:                                          ; preds = %bContinue
  %i15 = load i32, i32* %i, align 4
  %35 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 %i15
  %36 = load i32, i32* %35, align 4
  %i16 = load i32, i32* %i, align 4
  %37 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 %i16
  %38 = load i32, i32* %37, align 4
  %39 = sub nsw i32 %38, 1
  %40 = call i32 @getValue(i32 %36, i32 %39)
  %air17 = load i32, i32* @air, align 4
  %41 = icmp eq i32 %40, %air17
  %42 = zext i1 %41 to i32
  %i18 = load i32, i32* %i, align 4
  %43 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 %i18
  %44 = load i32, i32* %43, align 4
  %i19 = load i32, i32* %i, align 4
  %45 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 %i19
  %46 = load i32, i32* %45, align 4
  %47 = sub nsw i32 %46, 1
  %48 = call i32 @hasMonster(i32 %44, i32 %47)
  %49 = trunc i32 %48 to i1
  %50 = xor i1 %49, true
  %51 = zext i1 %50 to i32
  %52 = trunc i32 %42 to i1
  %53 = trunc i32 %51 to i1
  %54 = and i1 %52, %53
  %55 = zext i1 %54 to i32
  %56 = trunc i32 %55 to i1
  br i1 %56, label %bTrue13, label %bContinue14

bContinue11:                                      ; preds = %bContinue14, %bContinue
  %dir24 = load i32, i32* %dir, align 4
  %57 = icmp eq i32 %dir24, 1
  %58 = zext i1 %57 to i32
  %59 = trunc i32 %58 to i1
  br i1 %59, label %bTrue22, label %bContinue23

bTrue13:                                          ; preds = %bTrue10
  %i20 = load i32, i32* %i, align 4
  %60 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 %i20
  %61 = load i32, i32* %60, align 4
  %i21 = load i32, i32* %i, align 4
  %62 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 %i21
  %63 = load i32, i32* %62, align 4
  %64 = sub nsw i32 %63, 1
  store i32 %64, i32* %60, align 4
  ret i32 1
  br label %bContinue14

bContinue14:                                      ; preds = %bTrue13, %bTrue10
  br label %bContinue11

bTrue22:                                          ; preds = %bContinue11
  %i27 = load i32, i32* %i, align 4
  %65 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 %i27
  %66 = load i32, i32* %65, align 4
  %67 = sub nsw i32 %66, 1
  %i28 = load i32, i32* %i, align 4
  %68 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 %i28
  %69 = load i32, i32* %68, align 4
  %70 = call i32 @getValue(i32 %67, i32 %69)
  %air29 = load i32, i32* @air, align 4
  %71 = icmp eq i32 %70, %air29
  %72 = zext i1 %71 to i32
  %i30 = load i32, i32* %i, align 4
  %73 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 %i30
  %74 = load i32, i32* %73, align 4
  %75 = sub nsw i32 %74, 1
  %i31 = load i32, i32* %i, align 4
  %76 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 %i31
  %77 = load i32, i32* %76, align 4
  %78 = call i32 @hasMonster(i32 %75, i32 %77)
  %79 = trunc i32 %78 to i1
  %80 = xor i1 %79, true
  %81 = zext i1 %80 to i32
  %82 = trunc i32 %72 to i1
  %83 = trunc i32 %81 to i1
  %84 = and i1 %82, %83
  %85 = zext i1 %84 to i32
  %86 = trunc i32 %85 to i1
  br i1 %86, label %bTrue25, label %bContinue26

bContinue23:                                      ; preds = %bContinue26, %bContinue11
  %dir36 = load i32, i32* %dir, align 4
  %87 = icmp eq i32 %dir36, 0
  %88 = zext i1 %87 to i32
  %89 = trunc i32 %88 to i1
  br i1 %89, label %bTrue34, label %bContinue35

bTrue25:                                          ; preds = %bTrue22
  %i32 = load i32, i32* %i, align 4
  %90 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 %i32
  %91 = load i32, i32* %90, align 4
  %i33 = load i32, i32* %i, align 4
  %92 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 %i33
  %93 = load i32, i32* %92, align 4
  %94 = sub nsw i32 %93, 1
  store i32 %94, i32* %90, align 4
  ret i32 1
  br label %bContinue26

bContinue26:                                      ; preds = %bTrue25, %bTrue22
  br label %bContinue23

bTrue34:                                          ; preds = %bContinue23
  %i39 = load i32, i32* %i, align 4
  %95 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 %i39
  %96 = load i32, i32* %95, align 4
  %i40 = load i32, i32* %i, align 4
  %97 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 %i40
  %98 = load i32, i32* %97, align 4
  %99 = add nsw i32 %98, 1
  %100 = call i32 @getValue(i32 %96, i32 %99)
  %air41 = load i32, i32* @air, align 4
  %101 = icmp eq i32 %100, %air41
  %102 = zext i1 %101 to i32
  %i42 = load i32, i32* %i, align 4
  %103 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 %i42
  %104 = load i32, i32* %103, align 4
  %i43 = load i32, i32* %i, align 4
  %105 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 %i43
  %106 = load i32, i32* %105, align 4
  %107 = add nsw i32 %106, 1
  %108 = call i32 @hasMonster(i32 %104, i32 %107)
  %109 = trunc i32 %108 to i1
  %110 = xor i1 %109, true
  %111 = zext i1 %110 to i32
  %112 = trunc i32 %102 to i1
  %113 = trunc i32 %111 to i1
  %114 = and i1 %112, %113
  %115 = zext i1 %114 to i32
  %116 = trunc i32 %115 to i1
  br i1 %116, label %bTrue37, label %bContinue38

bContinue35:                                      ; preds = %bContinue38, %bContinue23
  ret i32 0

bTrue37:                                          ; preds = %bTrue34
  %i44 = load i32, i32* %i, align 4
  %117 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 %i44
  %118 = load i32, i32* %117, align 4
  %i45 = load i32, i32* %i, align 4
  %119 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 %i45
  %120 = load i32, i32* %119, align 4
  %121 = add nsw i32 %120, 1
  store i32 %121, i32* %117, align 4
  ret i32 1
  br label %bContinue38

bContinue38:                                      ; preds = %bTrue37, %bTrue34
  br label %bContinue35
}

define void @moveMonsterLeft(i32 %0) {
entry:
  %i = alloca i32, align 4
  store i32 %0, i32* %i, align 4
  %i1 = load i32, i32* %i, align 4
  %i2 = load i32, i32* %i, align 4
  %1 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i2
  %2 = load i32, i32* %1, align 4
  %3 = call i32 @roundSub(i32 %2)
  %4 = call i32 @tryMove(i32 %i1, i32 %3)
  %5 = trunc i32 %4 to i1
  br i1 %5, label %bTrue, label %bContinue

bTrue:                                            ; preds = %entry
  %i3 = load i32, i32* %i, align 4
  %6 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i3
  %7 = load i32, i32* %6, align 4
  %i4 = load i32, i32* %i, align 4
  %8 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i4
  %9 = load i32, i32* %8, align 4
  %10 = call i32 @roundSub(i32 %9)
  store i32 %10, i32* %6, align 4
  ret void
  br label %bContinue

bContinue:                                        ; preds = %bTrue, %entry
  %i7 = load i32, i32* %i, align 4
  %i8 = load i32, i32* %i, align 4
  %11 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i8
  %12 = load i32, i32* %11, align 4
  %13 = call i32 @tryMove(i32 %i7, i32 %12)
  %14 = trunc i32 %13 to i1
  br i1 %14, label %bTrue5, label %bContinue6

bTrue5:                                           ; preds = %bContinue
  ret void
  br label %bContinue6

bContinue6:                                       ; preds = %bTrue5, %bContinue
  %i11 = load i32, i32* %i, align 4
  %i12 = load i32, i32* %i, align 4
  %15 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i12
  %16 = load i32, i32* %15, align 4
  %17 = call i32 @roundAdd(i32 %16)
  %18 = call i32 @tryMove(i32 %i11, i32 %17)
  %19 = trunc i32 %18 to i1
  br i1 %19, label %bTrue9, label %bContinue10

bTrue9:                                           ; preds = %bContinue6
  %i13 = load i32, i32* %i, align 4
  %20 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i13
  %21 = load i32, i32* %20, align 4
  %i14 = load i32, i32* %i, align 4
  %22 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i14
  %23 = load i32, i32* %22, align 4
  %24 = call i32 @roundAdd(i32 %23)
  store i32 %24, i32* %20, align 4
  ret void
  br label %bContinue10

bContinue10:                                      ; preds = %bTrue9, %bContinue6
  %dir = alloca i32, align 4
  %i15 = load i32, i32* %i, align 4
  %25 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i15
  %26 = load i32, i32* %25, align 4
  %27 = call i32 @roundAdd(i32 %26)
  store i32 %27, i32* %dir, align 4
  %i18 = load i32, i32* %i, align 4
  %dir19 = load i32, i32* %dir, align 4
  %28 = call i32 @roundAdd(i32 %dir19)
  %29 = call i32 @tryMove(i32 %i18, i32 %28)
  %30 = trunc i32 %29 to i1
  br i1 %30, label %bTrue16, label %bContinue17

bTrue16:                                          ; preds = %bContinue10
  %i20 = load i32, i32* %i, align 4
  %31 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i20
  %32 = load i32, i32* %31, align 4
  %dir21 = load i32, i32* %dir, align 4
  %33 = call i32 @roundAdd(i32 %dir21)
  store i32 %33, i32* %31, align 4
  ret void
  br label %bContinue17

bContinue17:                                      ; preds = %bTrue16, %bContinue10
  ret void
}

define void @moveMonsterRight(i32 %0) {
entry:
  %i = alloca i32, align 4
  store i32 %0, i32* %i, align 4
  %i1 = load i32, i32* %i, align 4
  %i2 = load i32, i32* %i, align 4
  %1 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i2
  %2 = load i32, i32* %1, align 4
  %3 = call i32 @roundAdd(i32 %2)
  %4 = call i32 @tryMove(i32 %i1, i32 %3)
  %5 = trunc i32 %4 to i1
  br i1 %5, label %bTrue, label %bContinue

bTrue:                                            ; preds = %entry
  %i3 = load i32, i32* %i, align 4
  %6 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i3
  %7 = load i32, i32* %6, align 4
  %i4 = load i32, i32* %i, align 4
  %8 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i4
  %9 = load i32, i32* %8, align 4
  %10 = call i32 @roundAdd(i32 %9)
  store i32 %10, i32* %6, align 4
  ret void
  br label %bContinue

bContinue:                                        ; preds = %bTrue, %entry
  %i7 = load i32, i32* %i, align 4
  %i8 = load i32, i32* %i, align 4
  %11 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i8
  %12 = load i32, i32* %11, align 4
  %13 = call i32 @tryMove(i32 %i7, i32 %12)
  %14 = trunc i32 %13 to i1
  br i1 %14, label %bTrue5, label %bContinue6

bTrue5:                                           ; preds = %bContinue
  ret void
  br label %bContinue6

bContinue6:                                       ; preds = %bTrue5, %bContinue
  %i11 = load i32, i32* %i, align 4
  %i12 = load i32, i32* %i, align 4
  %15 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i12
  %16 = load i32, i32* %15, align 4
  %17 = call i32 @roundSub(i32 %16)
  %18 = call i32 @tryMove(i32 %i11, i32 %17)
  %19 = trunc i32 %18 to i1
  br i1 %19, label %bTrue9, label %bContinue10

bTrue9:                                           ; preds = %bContinue6
  %i13 = load i32, i32* %i, align 4
  %20 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i13
  %21 = load i32, i32* %20, align 4
  %i14 = load i32, i32* %i, align 4
  %22 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i14
  %23 = load i32, i32* %22, align 4
  %24 = call i32 @roundSub(i32 %23)
  store i32 %24, i32* %20, align 4
  ret void
  br label %bContinue10

bContinue10:                                      ; preds = %bTrue9, %bContinue6
  %dir = alloca i32, align 4
  %i15 = load i32, i32* %i, align 4
  %25 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i15
  %26 = load i32, i32* %25, align 4
  %27 = call i32 @roundAdd(i32 %26)
  store i32 %27, i32* %dir, align 4
  %i18 = load i32, i32* %i, align 4
  %dir19 = load i32, i32* %dir, align 4
  %28 = call i32 @roundAdd(i32 %dir19)
  %29 = call i32 @tryMove(i32 %i18, i32 %28)
  %30 = trunc i32 %29 to i1
  br i1 %30, label %bTrue16, label %bContinue17

bTrue16:                                          ; preds = %bContinue10
  %i20 = load i32, i32* %i, align 4
  %31 = getelementptr [5 x i32], [5 x i32]* @mdir, i32 0, i32 %i20
  %32 = load i32, i32* %31, align 4
  %dir21 = load i32, i32* %dir, align 4
  %33 = call i32 @roundAdd(i32 %dir21)
  store i32 %33, i32* %31, align 4
  ret void
  br label %bContinue17

bContinue17:                                      ; preds = %bTrue16, %bContinue10
  ret void
}

define void @moveMonsters() {
entry:
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %i1 = load i32, i32* %i, align 4
  %0 = icmp slt i32 %i1, 5
  %1 = zext i1 %0 to i32
  %2 = trunc i32 %1 to i1
  br i1 %2, label %lTrue, label %lContinue

lTrue:                                            ; preds = %bContinue, %entry
  %i2 = load i32, i32* %i, align 4
  %3 = getelementptr [5 x i32], [5 x i32]* @mpath, i32 0, i32 %i2
  %4 = load i32, i32* %3, align 4
  %5 = icmp eq i32 %4, 0
  %6 = zext i1 %5 to i32
  %7 = trunc i32 %6 to i1
  br i1 %7, label %bTrue, label %bFalse

lContinue:                                        ; preds = %bContinue, %entry
  ret void

bTrue:                                            ; preds = %lTrue
  %i3 = load i32, i32* %i, align 4
  call void @moveMonsterLeft(i32 %i3)
  br label %bContinue

bFalse:                                           ; preds = %lTrue
  %i4 = load i32, i32* %i, align 4
  call void @moveMonsterRight(i32 %i4)
  br label %bContinue

bContinue:                                        ; preds = %bFalse, %bTrue
  %i5 = load i32, i32* %i, align 4
  %8 = add nsw i32 %i5, 1
  store i32 %8, i32* %i, align 4
  %i6 = load i32, i32* %i, align 4
  %9 = icmp slt i32 %i6, 5
  %10 = zext i1 %9 to i32
  %11 = trunc i32 %10 to i1
  br i1 %11, label %lTrue, label %lContinue
}

define void @updateMonsterPaths() {
entry:
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %i1 = load i32, i32* %i, align 4
  %0 = icmp slt i32 %i1, 5
  %1 = zext i1 %0 to i32
  %2 = trunc i32 %1 to i1
  br i1 %2, label %lTrue, label %lContinue

lTrue:                                            ; preds = %bContinue, %entry
  %div = alloca i32, align 4
  %stepCounter = load i32, i32* @stepCounter, align 4
  %i2 = load i32, i32* %i, align 4
  %3 = getelementptr [5 x i32], [5 x i32]* @mChange, i32 0, i32 %i2
  %4 = load i32, i32* %3, align 4
  %5 = sdiv i32 %stepCounter, %4
  store i32 %5, i32* %div, align 4
  %div3 = load i32, i32* %div, align 4
  %i4 = load i32, i32* %i, align 4
  %6 = getelementptr [5 x i32], [5 x i32]* @mChange, i32 0, i32 %i4
  %7 = load i32, i32* %6, align 4
  %8 = mul nsw i32 %div3, %7
  %stepCounter5 = load i32, i32* @stepCounter, align 4
  %9 = icmp eq i32 %8, %stepCounter5
  %10 = zext i1 %9 to i32
  %11 = trunc i32 %10 to i1
  br i1 %11, label %bTrue, label %bContinue

lContinue:                                        ; preds = %bContinue, %entry
  ret void

bTrue:                                            ; preds = %lTrue
  %i6 = load i32, i32* %i, align 4
  %12 = getelementptr [5 x i32], [5 x i32]* @mpath, i32 0, i32 %i6
  %13 = load i32, i32* %12, align 4
  %i7 = load i32, i32* %i, align 4
  %14 = getelementptr [5 x i32], [5 x i32]* @mpath, i32 0, i32 %i7
  %15 = load i32, i32* %14, align 4
  %16 = sub nsw i32 %15, 1
  %i8 = load i32, i32* %i, align 4
  %17 = getelementptr [5 x i32], [5 x i32]* @mpath, i32 0, i32 %i8
  %18 = load i32, i32* %17, align 4
  %19 = sub nsw i32 %18, 1
  %20 = mul nsw i32 %16, %19
  store i32 %20, i32* %12, align 4
  br label %bContinue

bContinue:                                        ; preds = %bTrue, %lTrue
  %i9 = load i32, i32* %i, align 4
  %21 = add nsw i32 %i9, 1
  store i32 %21, i32* %i, align 4
  %i10 = load i32, i32* %i, align 4
  %22 = icmp slt i32 %i10, 5
  %23 = zext i1 %22 to i32
  %24 = trunc i32 %23 to i1
  br i1 %24, label %lTrue, label %lContinue
}

define void @handleBulletMove() {
entry:
  %bdir = load i32, i32* @bdir, align 4
  %0 = icmp eq i32 %bdir, 3
  %1 = zext i1 %0 to i32
  %2 = trunc i32 %1 to i1
  br i1 %2, label %bTrue, label %bContinue

bTrue:                                            ; preds = %entry
  %bx = load i32, i32* @bx, align 4
  %3 = add nsw i32 %bx, 1
  store i32 %3, i32* @bx, align 4
  br label %bContinue

bContinue:                                        ; preds = %bTrue, %entry
  %bdir3 = load i32, i32* @bdir, align 4
  %4 = icmp eq i32 %bdir3, 2
  %5 = zext i1 %4 to i32
  %6 = trunc i32 %5 to i1
  br i1 %6, label %bTrue1, label %bContinue2

bTrue1:                                           ; preds = %bContinue
  %by = load i32, i32* @by, align 4
  %7 = sub nsw i32 %by, 1
  store i32 %7, i32* @by, align 4
  br label %bContinue2

bContinue2:                                       ; preds = %bTrue1, %bContinue
  %bdir6 = load i32, i32* @bdir, align 4
  %8 = icmp eq i32 %bdir6, 1
  %9 = zext i1 %8 to i32
  %10 = trunc i32 %9 to i1
  br i1 %10, label %bTrue4, label %bContinue5

bTrue4:                                           ; preds = %bContinue2
  %bx7 = load i32, i32* @bx, align 4
  %11 = sub nsw i32 %bx7, 1
  store i32 %11, i32* @bx, align 4
  br label %bContinue5

bContinue5:                                       ; preds = %bTrue4, %bContinue2
  %bdir10 = load i32, i32* @bdir, align 4
  %12 = icmp eq i32 %bdir10, 0
  %13 = zext i1 %12 to i32
  %14 = trunc i32 %13 to i1
  br i1 %14, label %bTrue8, label %bContinue9

bTrue8:                                           ; preds = %bContinue5
  %by11 = load i32, i32* @by, align 4
  %15 = add nsw i32 %by11, 1
  store i32 %15, i32* @by, align 4
  br label %bContinue9

bContinue9:                                       ; preds = %bTrue8, %bContinue5
  ret void
}

define void @handleBulletHit() {
entry:
  %bx = load i32, i32* @bx, align 4
  %by = load i32, i32* @by, align 4
  %0 = call i32 @getValue(i32 %bx, i32 %by)
  %air = load i32, i32* @air, align 4
  %1 = icmp ne i32 %0, %air
  %2 = zext i1 %1 to i32
  %3 = trunc i32 %2 to i1
  br i1 %3, label %bTrue, label %bContinue

bTrue:                                            ; preds = %entry
  store i32 0, i32* @bx, align 4
  store i32 0, i32* @by, align 4
  store i32 10, i32* @bdir, align 4
  br label %bContinue

bContinue:                                        ; preds = %bTrue, %entry
  %bx3 = load i32, i32* @bx, align 4
  %by4 = load i32, i32* @by, align 4
  %4 = call i32 @hasMonster(i32 %bx3, i32 %by4)
  %5 = trunc i32 %4 to i1
  br i1 %5, label %bTrue1, label %bContinue2

bTrue1:                                           ; preds = %bContinue
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %i5 = load i32, i32* %i, align 4
  %6 = icmp slt i32 %i5, 5
  %7 = zext i1 %6 to i32
  %8 = trunc i32 %7 to i1
  br i1 %8, label %lTrue, label %lContinue

bContinue2:                                       ; preds = %lContinue, %bContinue
  ret void

lTrue:                                            ; preds = %bContinue7, %bTrue1
  %bx8 = load i32, i32* @bx, align 4
  %i9 = load i32, i32* %i, align 4
  %9 = getelementptr [5 x i32], [5 x i32]* @mx, i32 0, i32 %i9
  %10 = load i32, i32* %9, align 4
  %11 = icmp eq i32 %bx8, %10
  %12 = zext i1 %11 to i32
  %by10 = load i32, i32* @by, align 4
  %i11 = load i32, i32* %i, align 4
  %13 = getelementptr [5 x i32], [5 x i32]* @my, i32 0, i32 %i11
  %14 = load i32, i32* %13, align 4
  %15 = icmp eq i32 %by10, %14
  %16 = zext i1 %15 to i32
  %17 = trunc i32 %12 to i1
  %18 = trunc i32 %16 to i1
  %19 = and i1 %17, %18
  %20 = zext i1 %19 to i32
  %21 = trunc i32 %20 to i1
  br i1 %21, label %bTrue6, label %bContinue7

lContinue:                                        ; preds = %bContinue7, %bTrue1
  store i32 0, i32* @bx, align 4
  store i32 0, i32* @by, align 4
  store i32 10, i32* @bdir, align 4
  br label %bContinue2

bTrue6:                                           ; preds = %lTrue
  %i12 = load i32, i32* %i, align 4
  %22 = getelementptr [5 x i32], [5 x i32]* @mAlive, i32 0, i32 %i12
  %23 = load i32, i32* %22, align 4
  store i32 0, i32* %22, align 4
  br label %bContinue7

bContinue7:                                       ; preds = %bTrue6, %lTrue
  %i13 = load i32, i32* %i, align 4
  %24 = add nsw i32 %i13, 1
  store i32 %24, i32* %i, align 4
  %i14 = load i32, i32* %i, align 4
  %25 = icmp slt i32 %i14, 5
  %26 = zext i1 %25 to i32
  %27 = trunc i32 %26 to i1
  br i1 %27, label %lTrue, label %lContinue
}

define void @handleShoot() {
entry:
  %bdir = load i32, i32* @bdir, align 4
  %0 = icmp ne i32 %bdir, 10
  %1 = zext i1 %0 to i32
  %2 = trunc i32 %1 to i1
  br i1 %2, label %bTrue, label %bContinue

bTrue:                                            ; preds = %entry
  ret void
  br label %bContinue

bContinue:                                        ; preds = %bTrue, %entry
  %pdir = load i32, i32* @pdir, align 4
  store i32 %pdir, i32* @bdir, align 4
  %pdir3 = load i32, i32* @pdir, align 4
  %3 = icmp eq i32 %pdir3, 3
  %4 = zext i1 %3 to i32
  %5 = trunc i32 %4 to i1
  br i1 %5, label %bTrue1, label %bContinue2

bTrue1:                                           ; preds = %bContinue
  %px = load i32, i32* @px, align 4
  %6 = add nsw i32 %px, 1
  store i32 %6, i32* @bx, align 4
  %py = load i32, i32* @py, align 4
  store i32 %py, i32* @by, align 4
  br label %bContinue2

bContinue2:                                       ; preds = %bTrue1, %bContinue
  %pdir6 = load i32, i32* @pdir, align 4
  %7 = icmp eq i32 %pdir6, 2
  %8 = zext i1 %7 to i32
  %9 = trunc i32 %8 to i1
  br i1 %9, label %bTrue4, label %bContinue5

bTrue4:                                           ; preds = %bContinue2
  %py7 = load i32, i32* @py, align 4
  %10 = sub nsw i32 %py7, 1
  store i32 %10, i32* @by, align 4
  %px8 = load i32, i32* @px, align 4
  store i32 %px8, i32* @bx, align 4
  br label %bContinue5

bContinue5:                                       ; preds = %bTrue4, %bContinue2
  %pdir11 = load i32, i32* @pdir, align 4
  %11 = icmp eq i32 %pdir11, 1
  %12 = zext i1 %11 to i32
  %13 = trunc i32 %12 to i1
  br i1 %13, label %bTrue9, label %bContinue10

bTrue9:                                           ; preds = %bContinue5
  %px12 = load i32, i32* @px, align 4
  %14 = sub nsw i32 %px12, 1
  store i32 %14, i32* @bx, align 4
  %py13 = load i32, i32* @py, align 4
  store i32 %py13, i32* @by, align 4
  br label %bContinue10

bContinue10:                                      ; preds = %bTrue9, %bContinue5
  %pdir16 = load i32, i32* @pdir, align 4
  %15 = icmp eq i32 %pdir16, 0
  %16 = zext i1 %15 to i32
  %17 = trunc i32 %16 to i1
  br i1 %17, label %bTrue14, label %bContinue15

bTrue14:                                          ; preds = %bContinue10
  %py17 = load i32, i32* @py, align 4
  %18 = add nsw i32 %py17, 1
  store i32 %18, i32* @by, align 4
  %px18 = load i32, i32* @px, align 4
  store i32 %px18, i32* @bx, align 4
  br label %bContinue15

bContinue15:                                      ; preds = %bTrue14, %bContinue10
  ret void
}

define void @handleMove() {
entry:
  %pdir = load i32, i32* @pdir, align 4
  %0 = icmp eq i32 %pdir, 3
  %1 = zext i1 %0 to i32
  %2 = trunc i32 %1 to i1
  br i1 %2, label %bTrue, label %bContinue

bTrue:                                            ; preds = %entry
  %px = load i32, i32* @px, align 4
  %3 = add nsw i32 %px, 1
  %py = load i32, i32* @py, align 4
  %4 = call i32 @getValue(i32 %3, i32 %py)
  %air = load i32, i32* @air, align 4
  %5 = icmp eq i32 %4, %air
  %6 = zext i1 %5 to i32
  %7 = trunc i32 %6 to i1
  br i1 %7, label %bTrue1, label %bContinue2

bContinue:                                        ; preds = %bContinue2, %entry
  %pdir6 = load i32, i32* @pdir, align 4
  %8 = icmp eq i32 %pdir6, 2
  %9 = zext i1 %8 to i32
  %10 = trunc i32 %9 to i1
  br i1 %10, label %bTrue4, label %bContinue5

bTrue1:                                           ; preds = %bTrue
  %px3 = load i32, i32* @px, align 4
  %11 = add nsw i32 %px3, 1
  store i32 %11, i32* @px, align 4
  br label %bContinue2

bContinue2:                                       ; preds = %bTrue1, %bTrue
  br label %bContinue

bTrue4:                                           ; preds = %bContinue
  %px9 = load i32, i32* @px, align 4
  %py10 = load i32, i32* @py, align 4
  %12 = sub nsw i32 %py10, 1
  %13 = call i32 @getValue(i32 %px9, i32 %12)
  %air11 = load i32, i32* @air, align 4
  %14 = icmp eq i32 %13, %air11
  %15 = zext i1 %14 to i32
  %16 = trunc i32 %15 to i1
  br i1 %16, label %bTrue7, label %bContinue8

bContinue5:                                       ; preds = %bContinue8, %bContinue
  %pdir15 = load i32, i32* @pdir, align 4
  %17 = icmp eq i32 %pdir15, 1
  %18 = zext i1 %17 to i32
  %19 = trunc i32 %18 to i1
  br i1 %19, label %bTrue13, label %bContinue14

bTrue7:                                           ; preds = %bTrue4
  %py12 = load i32, i32* @py, align 4
  %20 = sub nsw i32 %py12, 1
  store i32 %20, i32* @py, align 4
  br label %bContinue8

bContinue8:                                       ; preds = %bTrue7, %bTrue4
  br label %bContinue5

bTrue13:                                          ; preds = %bContinue5
  %px18 = load i32, i32* @px, align 4
  %21 = sub nsw i32 %px18, 1
  %py19 = load i32, i32* @py, align 4
  %22 = call i32 @getValue(i32 %21, i32 %py19)
  %air20 = load i32, i32* @air, align 4
  %23 = icmp eq i32 %22, %air20
  %24 = zext i1 %23 to i32
  %25 = trunc i32 %24 to i1
  br i1 %25, label %bTrue16, label %bContinue17

bContinue14:                                      ; preds = %bContinue17, %bContinue5
  %pdir24 = load i32, i32* @pdir, align 4
  %26 = icmp eq i32 %pdir24, 0
  %27 = zext i1 %26 to i32
  %28 = trunc i32 %27 to i1
  br i1 %28, label %bTrue22, label %bContinue23

bTrue16:                                          ; preds = %bTrue13
  %px21 = load i32, i32* @px, align 4
  %29 = sub nsw i32 %px21, 1
  store i32 %29, i32* @px, align 4
  br label %bContinue17

bContinue17:                                      ; preds = %bTrue16, %bTrue13
  br label %bContinue14

bTrue22:                                          ; preds = %bContinue14
  %px27 = load i32, i32* @px, align 4
  %py28 = load i32, i32* @py, align 4
  %30 = add nsw i32 %py28, 1
  %31 = call i32 @getValue(i32 %px27, i32 %30)
  %air29 = load i32, i32* @air, align 4
  %32 = icmp eq i32 %31, %air29
  %33 = zext i1 %32 to i32
  %34 = trunc i32 %33 to i1
  br i1 %34, label %bTrue25, label %bContinue26

bContinue23:                                      ; preds = %bContinue26, %bContinue14
  ret void

bTrue25:                                          ; preds = %bTrue22
  %py30 = load i32, i32* @py, align 4
  %35 = add nsw i32 %py30, 1
  store i32 %35, i32* @py, align 4
  br label %bContinue26

bContinue26:                                      ; preds = %bTrue25, %bTrue22
  br label %bContinue23
}

define void @handleInput() {
entry:
  %input = alloca i32, align 4
  %0 = call i32 @in()
  store i32 %0, i32* %input, align 4
  %input1 = load i32, i32* %input, align 4
  %1 = icmp eq i32 %input1, 3
  %2 = zext i1 %1 to i32
  %3 = trunc i32 %2 to i1
  br i1 %3, label %bTrue, label %bContinue

bTrue:                                            ; preds = %entry
  %pdir = load i32, i32* @pdir, align 4
  %4 = add nsw i32 %pdir, 1
  store i32 %4, i32* @pdir, align 4
  %pdir4 = load i32, i32* @pdir, align 4
  %5 = icmp eq i32 %pdir4, 4
  %6 = zext i1 %5 to i32
  %7 = trunc i32 %6 to i1
  br i1 %7, label %bTrue2, label %bContinue3

bContinue:                                        ; preds = %bContinue3, %entry
  %input7 = load i32, i32* %input, align 4
  %8 = icmp eq i32 %input7, 2
  %9 = zext i1 %8 to i32
  %10 = trunc i32 %9 to i1
  br i1 %10, label %bTrue5, label %bContinue6

bTrue2:                                           ; preds = %bTrue
  store i32 0, i32* @pdir, align 4
  br label %bContinue3

bContinue3:                                       ; preds = %bTrue2, %bTrue
  br label %bContinue

bTrue5:                                           ; preds = %bContinue
  call void @handleMove()
  br label %bContinue6

bContinue6:                                       ; preds = %bTrue5, %bContinue
  %input10 = load i32, i32* %input, align 4
  %11 = icmp eq i32 %input10, 1
  %12 = zext i1 %11 to i32
  %13 = trunc i32 %12 to i1
  br i1 %13, label %bTrue8, label %bContinue9

bTrue8:                                           ; preds = %bContinue6
  %pdir11 = load i32, i32* @pdir, align 4
  %14 = sub nsw i32 %pdir11, 1
  store i32 %14, i32* @pdir, align 4
  %pdir14 = load i32, i32* @pdir, align 4
  %15 = sub nsw i32 0, 1
  %16 = icmp eq i32 %pdir14, %15
  %17 = zext i1 %16 to i32
  %18 = trunc i32 %17 to i1
  br i1 %18, label %bTrue12, label %bContinue13

bContinue9:                                       ; preds = %bContinue13, %bContinue6
  %input17 = load i32, i32* %input, align 4
  %19 = icmp eq i32 %input17, 0
  %20 = zext i1 %19 to i32
  %21 = trunc i32 %20 to i1
  br i1 %21, label %bTrue15, label %bContinue16

bTrue12:                                          ; preds = %bTrue8
  store i32 3, i32* @pdir, align 4
  br label %bContinue13

bContinue13:                                      ; preds = %bTrue12, %bTrue8
  br label %bContinue9

bTrue15:                                          ; preds = %bContinue9
  call void @handleShoot()
  br label %bContinue16

bContinue16:                                      ; preds = %bTrue15, %bContinue9
  %input20 = load i32, i32* %input, align 4
  %22 = icmp eq i32 %input20, 69
  %23 = zext i1 %22 to i32
  %24 = trunc i32 %23 to i1
  br i1 %24, label %bTrue18, label %bContinue19

bTrue18:                                          ; preds = %bContinue16
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %i21 = load i32, i32* %i, align 4
  %25 = icmp slt i32 %i21, 5
  %26 = zext i1 %25 to i32
  %27 = trunc i32 %26 to i1
  br i1 %27, label %lTrue, label %lContinue

bContinue19:                                      ; preds = %lContinue, %bContinue16
  %input27 = load i32, i32* %input, align 4
  %28 = icmp eq i32 %input27, 99
  %29 = zext i1 %28 to i32
  %30 = trunc i32 %29 to i1
  br i1 %30, label %bTrue25, label %bContinue26

lTrue:                                            ; preds = %lTrue, %bTrue18
  %i22 = load i32, i32* %i, align 4
  %31 = getelementptr [5 x i32], [5 x i32]* @mAlive, i32 0, i32 %i22
  %32 = load i32, i32* %31, align 4
  store i32 0, i32* %31, align 4
  %i23 = load i32, i32* %i, align 4
  %33 = add nsw i32 %i23, 1
  store i32 %33, i32* %i, align 4
  %i24 = load i32, i32* %i, align 4
  %34 = icmp slt i32 %i24, 5
  %35 = zext i1 %34 to i32
  %36 = trunc i32 %35 to i1
  br i1 %36, label %lTrue, label %lContinue

lContinue:                                        ; preds = %lTrue, %bTrue18
  br label %bContinue19

bTrue25:                                          ; preds = %bContinue19
  store i32 1, i32* @done, align 4
  br label %bContinue26

bContinue26:                                      ; preds = %bTrue25, %bContinue19
  ret void
}

define void @checkEnd() {
entry:
  %px = load i32, i32* @px, align 4
  %py = load i32, i32* @py, align 4
  %0 = call i32 @hasMonster(i32 %px, i32 %py)
  %px1 = load i32, i32* @px, align 4
  %1 = add nsw i32 %px1, 1
  %py2 = load i32, i32* @py, align 4
  %2 = call i32 @hasMonster(i32 %1, i32 %py2)
  %3 = trunc i32 %0 to i1
  %4 = trunc i32 %2 to i1
  %5 = or i1 %3, %4
  %6 = zext i1 %5 to i32
  %px3 = load i32, i32* @px, align 4
  %7 = sub nsw i32 %px3, 1
  %py4 = load i32, i32* @py, align 4
  %8 = call i32 @hasMonster(i32 %7, i32 %py4)
  %9 = trunc i32 %6 to i1
  %10 = trunc i32 %8 to i1
  %11 = or i1 %9, %10
  %12 = zext i1 %11 to i32
  %px5 = load i32, i32* @px, align 4
  %py6 = load i32, i32* @py, align 4
  %13 = add nsw i32 %py6, 1
  %14 = call i32 @hasMonster(i32 %px5, i32 %13)
  %15 = trunc i32 %12 to i1
  %16 = trunc i32 %14 to i1
  %17 = or i1 %15, %16
  %18 = zext i1 %17 to i32
  %px7 = load i32, i32* @px, align 4
  %py8 = load i32, i32* @py, align 4
  %19 = sub nsw i32 %py8, 1
  %20 = call i32 @hasMonster(i32 %px7, i32 %19)
  %21 = trunc i32 %18 to i1
  %22 = trunc i32 %20 to i1
  %23 = or i1 %21, %22
  %24 = zext i1 %23 to i32
  %25 = trunc i32 %24 to i1
  br i1 %25, label %bTrue, label %bFalse

bTrue:                                            ; preds = %entry
  store i32 1, i32* @done, align 4
  store i32 1, i32* @dead, align 4
  br label %bContinue

bFalse:                                           ; preds = %entry
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %i9 = load i32, i32* %i, align 4
  %26 = icmp slt i32 %i9, 5
  %27 = zext i1 %26 to i32
  %28 = trunc i32 %27 to i1
  br i1 %28, label %lTrue, label %lContinue

bContinue:                                        ; preds = %lContinue, %bTrue
  ret void

lTrue:                                            ; preds = %bContinue11, %bFalse
  %i12 = load i32, i32* %i, align 4
  %29 = getelementptr [5 x i32], [5 x i32]* @mAlive, i32 0, i32 %i12
  %30 = load i32, i32* %29, align 4
  %31 = trunc i32 %30 to i1
  br i1 %31, label %bTrue10, label %bContinue11

lContinue:                                        ; preds = %bContinue11, %bFalse
  store i32 1, i32* @done, align 4
  store i32 1, i32* @won, align 4
  br label %bContinue

bTrue10:                                          ; preds = %lTrue
  ret void
  br label %bContinue11

bContinue11:                                      ; preds = %bTrue10, %lTrue
  %i13 = load i32, i32* %i, align 4
  %32 = add nsw i32 %i13, 1
  store i32 %32, i32* %i, align 4
  %i14 = load i32, i32* %i, align 4
  %33 = icmp slt i32 %i14, 5
  %34 = zext i1 %33 to i32
  %35 = trunc i32 %34 to i1
  br i1 %35, label %lTrue, label %lContinue
}

define i32 @program() {
entry:
  call void @makeMap()
  call void @makeMonsters()
  call void @print(i8* getelementptr inbounds ([80 x i8], [80 x i8]* @0, i32 0, i32 0))
  %newLine = load i32, i32* @newLine, align 4
  call void @outChar(i32 %newLine)
  %done = load i32, i32* @done, align 4
  %0 = trunc i32 %done to i1
  %1 = xor i1 %0, true
  %2 = zext i1 %1 to i32
  %3 = trunc i32 %2 to i1
  br i1 %3, label %lTrue, label %lContinue

lTrue:                                            ; preds = %lTrue, %entry
  %stepCounter = load i32, i32* @stepCounter, align 4
  %4 = add nsw i32 %stepCounter, 1
  store i32 %4, i32* @stepCounter, align 4
  call void @printMap()
  call void @handleBulletMove()
  call void @handleInput()
  call void @handleBulletHit()
  call void @moveMonsters()
  call void @handleBulletHit()
  call void @updateMonsterPaths()
  call void @checkEnd()
  %done1 = load i32, i32* @done, align 4
  %5 = trunc i32 %done1 to i1
  %6 = xor i1 %5, true
  %7 = zext i1 %6 to i32
  %8 = trunc i32 %7 to i1
  br i1 %8, label %lTrue, label %lContinue

lContinue:                                        ; preds = %lTrue, %entry
  call void @printMap()
  %won = load i32, i32* @won, align 4
  %9 = trunc i32 %won to i1
  br i1 %9, label %bTrue, label %bContinue

bTrue:                                            ; preds = %lContinue
  call void @print(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @1, i32 0, i32 0))
  br label %bContinue

bContinue:                                        ; preds = %bTrue, %lContinue
  %dead = load i32, i32* @dead, align 4
  %10 = trunc i32 %dead to i1
  br i1 %10, label %bTrue2, label %bContinue3

bTrue2:                                           ; preds = %bContinue
  call void @print(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @2, i32 0, i32 0))
  br label %bContinue3

bContinue3:                                       ; preds = %bTrue2, %bContinue
  ret i32 2
}
