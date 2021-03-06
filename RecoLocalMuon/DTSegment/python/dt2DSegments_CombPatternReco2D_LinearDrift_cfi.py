import FWCore.ParameterSet.Config as cms

# Module for 2D rechit building 
# The algo uses the Linear Drift Velocity (which is a 1D rec hit algo)
# The block of the reconstruction algo
from RecoLocalMuon.DTSegment.DTCombinatorialPatternReco2DAlgo_LinearDrift_cfi import *
dt2DSegments = cms.EDProducer("DTRecSegment2DProducer",
    # The reconstruction algo and its parameter set
    DTCombinatorialPatternReco2DAlgo_LinearDrift,
    # debuggin opt
    debug = cms.untracked.bool(False),
    # name of the rechit 1D collection in the event
    recHits1DLabel = cms.InputTag("dt1DRecHits")
)


#add cosmics reconstruction in collisions
from RecoLocalMuon.DTSegment.DTCombinatorialPatternReco2DAlgo_LinearDrift_CosmicData_cfi import *
dt2DCosmicSegments = cms.EDProducer("DTRecSegment2DProducer",
    # The reconstruction algo and its parameter set
    DTCombinatorialPatternReco2DAlgo_LinearDrift_CosmicData,
    # debuggin opt
    debug = cms.untracked.bool(False),
    # name of the rechit 1D collection in the event
    recHits1DLabel = cms.InputTag("dt1DCosmicRecHits")
)
