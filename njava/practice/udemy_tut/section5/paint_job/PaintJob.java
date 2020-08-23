public class PaintJob {
	public static int getBucketCount(double width, double height, double areaPerBucket, int extraBuckets) {
		if ((width <= 0 || height <= 0 || areaPerBucket <= 0) || extraBuckets < 0) {
			return -1;
		}
		double areaOfWall = width * height;
		double currentAreaCompletion = extraBuckets * areaPerBucket;
		int bucketsToBuy = 0;
		while (currentAreaCompletion < areaOfWall) {
			++bucketsToBuy;
			currentAreaCompletion += areaPerBucket;
		}
		return bucketsToBuy;
	}

	// overload method getBucketCount
	public static int getBucketCount(double width, double height, double areaPerBucket) {
		if (width <= 0 || height <= 0 || areaPerBucket <= 0) {
			return -1;
		}
		double areaOfWall = width * height;
		double currentAreaCompletion = 0;
		int bucketsToBuy = 0;
		while (currentAreaCompletion < areaOfWall) {
			++bucketsToBuy;
			currentAreaCompletion += areaPerBucket;
		}
		return bucketsToBuy;
	}

	// another overload method getBucketCount
	public static int getBucketCount(double area, double areaPerBucket) {
		if (area <= 0 || areaPerBucket <= 0) {
			return -1;
		}
		double currentAreaCompletion = 0;
		int bucketsToBuy = 0;
		while (currentAreaCompletion < area) {
			++bucketsToBuy;
			currentAreaCompletion += areaPerBucket;
		}
		return bucketsToBuy;
	}
}
