# [Gold III] Stable Wall - 23906 

[문제 링크](https://www.acmicpc.net/problem/23906) 

### 성능 요약

메모리: 2028 KB, 시간: 8 ms

### 분류

방향 비순환 그래프, 그래프 이론, 위상 정렬

### 제출 일자

2025년 5월 4일 07:04:31

### 문제 설명

<p>Apollo is playing a game involving polyominos. A polyomino is a shape made by joining together one or more squares edge to edge to form a single connected shape. The game involves combining <b>N</b> polyominos into a single rectangular shape without any holes. Each polyomino is labeled with a unique character from <code>A</code> to <code>Z</code>.</p>

<p>Apollo has finished the game and created a rectangular wall containing <b>R</b> rows and <b>C</b> columns. He took a picture and sent it to his friend Selene. Selene likes pictures of walls, but she likes them even more if they are <i>stable</i> walls. A wall is stable if it can be created by adding polyominos one at a time to the wall so that each polyomino is always <i>supported</i>. A polyomino is supported if each of its squares is either on the ground, or has another square below it.</p>

<p>Apollo would like to check if his wall is stable and if it is, prove that fact to Selene by telling her the order in which he added the polyominos.</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <b>T</b>. <b>T</b> test cases follow. Each test case begins with a line containing the two integers <b>R</b> and <b>C</b>. Then, <b>R</b> lines follow, describing the wall from top to bottom. Each line contains a string of <b>C</b> uppercase characters from <code>A</code> to <code>Z</code>, describing that row of the wall.</p>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y</code>, where <code>x</code> is the test case number (starting from 1) and <code>y</code> is a string of <b>N</b> uppercase characters, describing the order in which he built them. If there is more than one such order, output any of them. If the wall is not stable, output <code>-1</code> instead.</p>

