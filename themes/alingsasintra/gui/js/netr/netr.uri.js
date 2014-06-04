netr.URI = function (uriString) {
	if (uriString && typeof uriString == 'string') {
		this.set(uriString);
	}
};
netr.URI.prototype = {

	scheme: '',
	domain: '',
	port: '',
	path: '',
	query: '',
	fragment: '',

	set: function (uriString) {
		var parts;

		if (/^#/.test(uriString)) {
			// It's just a fragment!
			this.fragment = uriString.replace(/^#/, ''); // Remove leading hash sign

		} else if (!(/^.+:\/\//.test(uriString))) {
			// It's a relative URL!
			parts = /^([^?#]+)?([^#]+)?(.*)$/.exec(uriString);
			this.path = parts[1] || '';
			this.query = parts[2] ? netr.URI.parseQuery(parts[2]) : {};
			this.fragment = parts[3].replace(/^#/, ''); // Remove leading hash sign

		} else {
			// It's an absolute URL!
			parts = /^(.+?:\/\/)?([^#?\/]+)?(\/*[^?#]+)?([^#]+)?(.*)$/.exec(uriString);
			// Split the host part into domain and port
			var host = /([^:]+):*([^:]*)/.exec(parts[2]);

			this.scheme = parts[1].replace('://', '');
			this.domain = host ? host[1] : '';
			this.port = host ? host[2] : '';
			this.path = parts[3];
			this.query = parts[4] ? netr.URI.parseQuery(parts[4]) : {};
			this.fragment = parts[5].replace(/^#/, ''); // Remove leading hash sign
		}

	},
	getAbsolute: function (base) {
		base = new netr.URI(base || document.location.href);

		var uri = new netr.URI(this.toString());

		uri.scheme = uri.scheme || base.scheme;
		uri.domain = uri.domain || base.domain;
		uri.port = uri.port || base.port;

		if (uri.path) {
		 	if (!(/^\//.test(uri.path))) {
				// Path is relative
				if (/\..+$/.test(base.path)) {
					// Document location ends with a suffix
					uri.path = (base.path || '').replace(/\/[^\/]*$/, '') + '/' + uri.path;
				} else {
					// Document location ends with a folder
					uri.path = (base.path || '').replace('/\/+$/', '') + '/' + uri.path;
				}
			}
		} else {
			uri.path = base.path;
		}

		return uri.toString();
	},
	getSecondLevelDomain: function () {
		var match = this.domain.match(/\w+\.\w+$/);
		return match ? match[0] : null;
	},
	toString: function () {
		return [
			this.scheme ? this.scheme + '://' : '',
			this.domain,
			this.port ? ':' + this.port : '',
			this.path,
			netr.URI.objectToQueryString(this.query),
			this.fragment ? '#' + this.fragment : ''
		].join('');
	}
};

// Utility methods
netr.URI.parseQuery = function (queryString) {
	var ret = {};
	// Remove leading question mark
	var queryString = queryString.replace(/^\?/, '');

	if (queryString.length) {
		var pairs = queryString.split('&');

		function parsePairs (pair) {
			pair = pair.split('=');
			var key = pair[0];
			var val = pair[1].split(',');

			if (key in ret) {
				if (!(ret[key] instanceof Array)) {
					ret[key] = [ret[key]];
				}
				ret[key] = ret[key].concat(val);
			} else {
				ret[key] = val.length > 1 ? val : val[0];
			}
		}

		for (var i = 0, l = pairs.length; i < l; i++) {
			parsePairs(pairs[i]);
		}
	}

	return ret;
};
netr.URI.objectToQueryString = function (queryObject) {
	var join;

	function joinPair (obj) {
		var ret = '';
		for (var key in obj) {
			if (obj.hasOwnProperty(key)) {
				ret += '&' + encodeURIComponent(key) + '=';
				if (obj[key].toString) {
					ret += encodeURIComponent(obj[key].toString());
				} else {
					ret += encodeURIComponent(joinPair(obj[key]));
				}
			}
		}
		return ret;
	}

	join = joinPair(queryObject).replace(/^&/, '');
	return join ? '?' + join : '';
};