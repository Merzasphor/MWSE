#pragma once

namespace mwse {
	namespace mcp {
		// Type of the storage we use for keeping track of MCP features.
		typedef std::map<long, bool> FeatureStoreMap_t;

		// Storage for the features we've detected as installed by MCP.
		extern FeatureStoreMap_t featureStore;

		// Loads the feature list from MCP files.
		bool loadFeatureList();

		// Returns true if a given feature is enabled.
		bool getFeatureEnabled(long id);

		// Returns true if MWSE was able to parse features.
		bool hasFeaturesFound();
	}
}
