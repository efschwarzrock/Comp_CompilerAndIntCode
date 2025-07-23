; ModuleID = '123'
source_filename = "123"

@map = common global [100 x i32]
@wall = dso_local global i32 35
@air = dso_local global i32 32
@newLine = dso_local global i32 10

declare i32 @in()

declare void @outChar(i32)

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

define void @makeMap() {
entry:
  call void @outChar(i32 68)
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
  call void @outChar(i32 69)
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
  call void @outChar(i32 70)
  call void @outChar(i32 75)
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
  call void @setValue(i32 4, i32 1, i32 %wall29)
  %wall30 = load i32, i32* @wall, align 4
  call void @setValue(i32 4, i32 2, i32 %wall30)
  %wall31 = load i32, i32* @wall, align 4
  call void @setValue(i32 5, i32 1, i32 %wall31)
  %wall32 = load i32, i32* @wall, align 4
  call void @setValue(i32 5, i32 2, i32 %wall32)
  %wall33 = load i32, i32* @wall, align 4
  call void @setValue(i32 5, i32 4, i32 %wall33)
  %wall34 = load i32, i32* @wall, align 4
  call void @setValue(i32 5, i32 5, i32 %wall34)
  %wall35 = load i32, i32* @wall, align 4
  call void @setValue(i32 5, i32 6, i32 %wall35)
  %wall36 = load i32, i32* @wall, align 4
  call void @setValue(i32 5, i32 8, i32 %wall36)
  %wall37 = load i32, i32* @wall, align 4
  call void @setValue(i32 6, i32 5, i32 %wall37)
  %wall38 = load i32, i32* @wall, align 4
  call void @setValue(i32 7, i32 2, i32 %wall38)
  %wall39 = load i32, i32* @wall, align 4
  call void @setValue(i32 7, i32 3, i32 %wall39)
  %wall40 = load i32, i32* @wall, align 4
  call void @setValue(i32 7, i32 7, i32 %wall40)
  %wall41 = load i32, i32* @wall, align 4
  call void @setValue(i32 8, i32 5, i32 %wall41)
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

define void @printMap() {
entry:
  call void @outChar(i32 71)
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

lTrue2:                                           ; preds = %lTrue2, %lTrue
  %v = alloca i32, align 4
  %i5 = load i32, i32* %i, align 4
  %j6 = load i32, i32* %j, align 4
  %6 = call i32 @getValue(i32 %i5, i32 %j6)
  store i32 %6, i32* %v, align 4
  %v7 = load i32, i32* %v, align 4
  call void @outChar(i32 %v7)
  %j8 = load i32, i32* %j, align 4
  %7 = add nsw i32 %j8, 1
  store i32 %7, i32* %j, align 4
  %j9 = load i32, i32* %j, align 4
  %8 = icmp slt i32 %j9, 10
  %9 = zext i1 %8 to i32
  %10 = trunc i32 %9 to i1
  br i1 %10, label %lTrue2, label %lContinue3

lContinue3:                                       ; preds = %lTrue2, %lTrue
  %newLine = load i32, i32* @newLine, align 4
  call void @outChar(i32 %newLine)
  %i10 = load i32, i32* %i, align 4
  %11 = add nsw i32 %i10, 1
  store i32 %11, i32* %i, align 4
  %i11 = load i32, i32* %i, align 4
  %12 = icmp slt i32 %i11, 10
  %13 = zext i1 %12 to i32
  %14 = trunc i32 %13 to i1
  br i1 %14, label %lTrue, label %lContinue
}

define i32 @program() {
entry:
  call void @makeMap()
  call void @printMap()
  ret i32 2
}
