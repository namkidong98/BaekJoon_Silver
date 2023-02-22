//다음 순열(실버 3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int target[10000];
int tmp[10000];

int main() {
	int count = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &target[i]);
	}
	
	int i;
	//뒤에서부터 읽어서 바로 앞의 index가 더 작은 경우를 발견하면 멈춘다 (count를 증가시키면서 읽다가)
	for (i = N - 1; i >= 1; i--) {
		if (target[i] < target[i - 1]) count++;
		else break;
	}

	//count가 N-1이면 뒤에서부터 쭉 증가한다는 것으로 마지막 순열임을 뜻하고 이때는 -1을 출력하고 종료한다
	if (count == N - 1) {
		printf("-1");
		return 0;
	}

	//그 다음으로 앞의 index가 작아진 경우, 그 index보다 바로 다음으로 큰 값을 뒤에서부터 읽으면서 찾아낸 후
	int next = target[i - 1];
	int index = i;
	int first = 1;
	for (int j = N - 1; j >= i; j--) {
		if (first == 1 && target[j] > next) {
			next = target[j];
			index = j;
			first = 0;
		}
		else if (first == 0 && target[j] < next && target[j] > target[i - 1]) {
			next = target[j];
			index = j;
		}
	}
	
	//해당 index보다 바로 다음으로 큰 값을 찾았으면 swap한다
	int temp = target[i - 1];
	target[i - 1] = target[index];
	target[index] = temp;

	//이제 해당 index(i-1)보다 큰부분은 뒤집어서 tmp에 저장한다
	int k = 0;
	for (int j = N - 1; j >= i; j--) {
		tmp[k++] = target[j];
	}

	//앞부분은 변하지 않았으므로 값을 입력 받아왔던 target에서 해당 index인 i-1까지 그대로 출력하고
	for (int x = 0; x <= i - 1; x++) {
		printf("%d ", target[x]);
	}

	//그 뒷부분을 뒤집어서 저장했던 tmp를 순차적으로 출력하면 입력받은 target 순열의 바로 다음 순열이 된다
	for (int x = 0; x <= count; x++) {
		printf("%d ", tmp[x]);
	}
}

//재귀 함수를 사용하여 주어진 순열을 찾고 그 바로 다음 순열을 출력하는, 브루트 포스 방식으로 찾는 것은 시간이 많이 걸려서 시간초과가 발생한다.