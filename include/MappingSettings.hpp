//
// Created by Lukas Burgholzer on 29.02.20.
//

#ifndef QMAP_MAPPINGSETTINGS_HPP
#define QMAP_MAPPINGSETTINGS_HPP

/// Identity: q_i -> Q_i
/// Static: first layer is mapped q_c -> Q_c and q_t -> Q_t
/// Dynamic: Layout is generated on demand upon encountering a specific gate
enum class InitialLayoutStrategy {
	Identity, Static, Dynamic, None
};
static std::string toString(const InitialLayoutStrategy strategy) {
	switch (strategy) {
		case InitialLayoutStrategy::Identity:
			return "identity";
		case InitialLayoutStrategy::Static:
			return "static";
		case InitialLayoutStrategy::Dynamic:
			return "dynamic";
		case InitialLayoutStrategy::None:
			return "none";
	}
	return " ";
}

enum class LayeringStrategy {
	IndividualGates, DisjointQubits, OddGates, QubitTriangle, None
};
static std::string toString(const LayeringStrategy strategy) {
	switch (strategy) {
		case LayeringStrategy::IndividualGates:
			return "individual gates";
		case LayeringStrategy::DisjointQubits:
			return "disjoint qubits";
		case LayeringStrategy::OddGates:
			return "odd gates";
		case LayeringStrategy::QubitTriangle:
			return "qubit triangle";
		case LayeringStrategy::None:
			return "none";
	}
	return " ";
}

struct MappingSettings {
	MappingSettings() = default;

	unsigned int timeout = 3600000; // 60min timeout
	void setTimeout(unsigned int sec) { timeout = sec;}

	LayeringStrategy layeringStrategy = LayeringStrategy::None;

	/// Settings for heuristic approach
	InitialLayoutStrategy initialLayoutStrategy = InitialLayoutStrategy::None;

	bool admissibleHeuristic = true;
	bool verbose = false;

	bool lookahead = true;
	int nrLookaheads = 15;
	double firstLookaheadFactor = 0.75;
	double lookaheadFactor = 0.5;

};

#endif //QMAP_MAPPINGSETTINGS_HPP