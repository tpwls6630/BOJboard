# [Gold II] Martian DNA - 15862 

[문제 링크](https://www.acmicpc.net/problem/15862) 

### 성능 요약

메모리: 4372 KB, 시간: 36 ms

### 분류

이분 탐색, 두 포인터, 매개 변수 탐색

### 제출 일자

2025년 10월 30일 11:49:29

### 문제 설명

<p>As you are probably aware, human DNA can be represented as a long string over an alphabet of size four (A, C, G, T), where each symbol represents a distinct nucleobase (respectively; adenine, cytosine, guanine, and thymine).</p>

<p>For martians, however, things are a bit different; research conducted on the latest martian captured by NASA revealed that martian DNA consists of a whopping K distinct nucleobases! Martian DNA may thus be represented as a string over an alphabet of size K.</p>

<p>Now, a certain research group interested in exploiting martian DNA in artificial intelligence applications has requested to get a single consecutive piece of a martian DNA string. For R of the nucleobases, they have specified a minimum quantity of how many they need of that particular nucleobase to be present in their sample.</p>

<p>You are interested in finding the shortest substring of the DNA which satisfies their requirements.</p>

### 입력 

 <p>The first line contains three integers N, K, and R, denoting the total length of the martian DNA, the alphabet size, and the number of nucleobases for which the researchers have a minimum quantity requirement, respectively. They obey 1 ≤ R ≤ K ≤ N.</p>

<p>The second line contains N space-separated integers: the complete martian DNA string. The i-th of these integers, D<sub>i</sub>, indicates what nucleobase is in the i-th position of the DNA string. Nucleobases are 0-indexed, i.e. 0 ≤ D<sub>i</sub> < K. Each nucleobase will occur at least once in the DNA string.</p>

<p>Each of the following R lines contains two integers B and Q representing a nucleobase and its mimimum required quantity, respectively (0 ≤ B < K, 1 ≤ Q ≤ N). No nucleobase will be listed more than once in these R lines.</p>

### 출력 

 <p>Output a single integer, the length of the shortest consecutive substring of the DNA that satisfies the researchers’ requirements. If no such substring exists, output “impossible”.</p>

