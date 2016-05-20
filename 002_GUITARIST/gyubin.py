# Python3
# N개의 연주곡. 매 곡이 시작하기 전에 볼륨을 바꿀 것.
# 볼륨 바꾸는 리스트 V. V[i]는 i 번째 곡을 연주하기 직전에 바꿀 볼륨 값
# 현재 볼륨 P에서 +V[i] 하거나 -V[i]하면 된다. 0 미만 혹 M 초과는 안된다.
# 곡의 개수 N, 시작 볼륨 S, 최대 볼륨 M이 주어짐. 1 ≤ N ≤ 100, 1 ≤ M ≤ 1000, 0 ≤ S ≤ M
# 마지막 곡을 연주할 수 있는 볼륨 중 최대값을 출력.
# 마지막곡을 연주할 수 없다면, 더했을 때 최대치 넘거나, 뺐을 때 0 미만일 수밖에 없다면 -1 출력

def slow_recursive():
    num_song, start_volume, max_volume = [int(i) for i in input().split(' ')]
    volumes = [int(i) for i in input().split(' ')]

    result = []
    def get_next_volume(cur, index):
        if index == len(volumes):
            result.append(cur)
        else:
            if cur + volumes[index] <= max_volume:
                get_next_volume(cur+volumes[index], index + 1)
            if cur - volumes[index] >= 0:
                get_next_volume(cur-volumes[index], index + 1)
        return

    get_next_volume(start_volume, 0)
    if result:
        print(max(result))
    else:
        print(-1)


def just_for():
    from copy import deepcopy
    num_song, start_volume, max_volume = [int(i) for i in input().split(' ')]
    volumes = [int(i) for i in input().split(' ')]

    result = [start_volume]
    for volume in volumes:
        temp = set([])
        for candidate in result:
            if candidate + volume <= max_volume:
                temp.add(candidate + volume)
            if candidate - volume >= 0:
                temp.add(candidate - volume)
        result = deepcopy(temp)

    if result:
        print(max(result))
    else:
        print(-1)

if __name__ == '__main__':
    # slow_recursive()
    just_for()
