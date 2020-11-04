const getSecret = (secret) => {
	return {
		get: () => secret
	};
};

test('Closure for object privacy.', assert => {
	const msg = '.get() should have access to closure.';
	const expected = 1;
	const obj = getSecret(1);

	const actual = obj.get();

	try {
		assert.ok(secret, 'This throws an error');
	}
	catch (e) {
		assert.ok(true, 'The secret var is only available to privileged methods.');
	}

	assert.equal(actual, expected, msg);
	assert.end();
})

/* In the above example, the '.get()' method is defined inside the scope of
 * 'getSecret()', which gives it access to any variables from 'getSecret()',
 * and makes it privileged method. In this case, the parameter, 'secret'. */
