int nX; 
	int nY;
	printf("Enter first number: ");
	scanf("%d", &nX);
	printf("\n");
	printf("Enter second number: ");
	scanf(" %d", &nY);
	printf("\n");
	if (nX == nY) {
		printf("%d and %d are equal\n", nX, nY);
	}
	else {
		printf("%d and %d are not equal\n", nX, nY);
	}
	if (nX > nY) {
		printf("%d is greater than %d\n", nX, nY);
	}
	

	(nX != nY) ? printf("%d and %d are different \n", nX, nY) : printf("%d and %d are the same\n", nX, nY);
