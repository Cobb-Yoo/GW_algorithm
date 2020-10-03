노드 삭제하는 함수는 구현하지 않았음... ㅠ

삭제가 진행되는 노드의 전 노드를 확인한다음에
함수에 전 노드를 보내고
삭제할 노드를 deletedNode로 명시한 다음에

전 노드 (부모노드)의 링크를 deletedNode->link로 재설정한다음에

free(deletedNode) 하면 됨 ㅇㅇ