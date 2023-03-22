# [Platinum III] Joining Pairs - 24992 

[문제 링크](https://www.acmicpc.net/problem/24992) 

### 성능 요약

메모리: 14960 KB, 시간: 124 ms

### 분류

자료 구조, 기하학, 스택

### 문제 설명

<p>Alexander and Melina are really good friends. After a long summer of playing games together, they finally had to take the bus back home. Since they had such an active summer, they were getting bored from the bus ride, so Alexander challenged Melina to one final puzzle.</p>

<p>Alexander gave Melina a piece of graph paper W centimeters wide and H centimeters tall. The paper was subdivided into 1 × 1 squares, forming a W × H coordinate system. In the paper, Alexander had drawn many colorful points, in such a way that there were exactly two points of each color, all points were at integer coordinates (possibly including the edges and corners of the paper) and there were no two points in the same spot.</p>

<p>Alexander asked Melina to draw a line between each pair of equally colored points, connecting them. The lines connecting the points couldn’t touch each other. However, they could assume an arbitrary shape (as long as they remained inside the paper) and they could be considered infinitely thin.</p>

<p>Melina argued with Alexander that the game was unfair since there was no way to satisfy his requirements. Alexander assured her that the game was fair, and she simply had to “get good” to solve the challenge. After much arguing, the friends decided to task you, an unbiased observer, with determining whether the game is fair or not.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/ef3b8203-3b15-45eb-a651-7513049b7533/-/preview/" style="width: 365px; height: 186px;"></p>

<p>In the example above, Melina can connect each pair of points without crossing lines, therefore the game is fair. On the contrary, in the example below, Melina can’t connect the twos without crossing whichever line connects the ones, therefore the game is not fair.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/60e392e5-d16d-4bee-a2b2-29fb3fe992b7/-/preview/" style="width: 185px; height: 186px;"></p>

### 입력 

 <p>The first line contains two integers W and H (1 ≤ W, H ≤ 10<sup>9</sup>), indicating respectively the width and height of the paper. The second line contains an integer N (1 ≤ N ≤ 10<sup>5</sup>), representing the number of pairs of points drawn in the paper. Each of the next N lines contains four integers X<sub>1</sub>, Y<sub>1</sub>, X<sub>2</sub> and Y<sub>2</sub> (0 ≤ X<sub>1</sub>, X<sub>2</sub> ≤ W and 0 ≤ Y<sub>1</sub>, Y<sub>2</sub> ≤ H), representing a pair of points of the same color drawn at coordinates (X<sub>1</sub>, Y<sub>1</sub>) and (X<sub>2</sub>, Y<sub>2</sub>). No two points have the same location.</p>

### 출력 

 <p>Output a single line with the uppercase letter “<code>Y</code>” if the game is fair, and the uppercase letter “<code>N</code>” otherwise.</p>

