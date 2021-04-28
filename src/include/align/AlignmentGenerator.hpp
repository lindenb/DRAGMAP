/**
 ** DRAGEN Open Source Software
 ** Copyright (c) 2019-2020 Illumina, Inc.
 ** All rights reserved.
 **
 ** This software is provided under the terms and conditions of the
 ** GNU GENERAL PUBLIC LICENSE Version 3
 **
 ** You should have received a copy of the GNU GENERAL PUBLIC LICENSE Version 3
 ** along with this program. If not, see
 ** <https://github.com/illumina/licenses/>.
 **
 **/

#ifndef ALIGN_ALIGNMENT_GENERATOR_HPP
#define ALIGN_ALIGNMENT_GENERATOR_HPP

#include "align/Alignments.hpp"
#include "map/ChainBuilder.hpp"
#include "reference/ReferenceDir.hpp"
#include "sequences/Read.hpp"

namespace dragenos {
namespace align {

class AlignmentGenerator {
public:
  typedef sequences::Read   Read;
  typedef map::ChainBuilder ChainBuilder;
  AlignmentGenerator(
      const reference::ReferenceDir& referenceDir, SmithWaterman& smithWaterman)
    : referenceDir_(referenceDir), smithWaterman_(smithWaterman)
  {
  }
  /// delegate for the Aligner generateAlignments method
  void generateAlignments(const Read& read, const map::ChainBuilder& chainBuilder, Alignments& alignments);
  bool generateAlignment(const ScoreType alnMinScore, const Read& read, const map::SeedChain& seedChain, Alignment& alignment);

private:
  const reference::ReferenceDir& referenceDir_;
  SmithWaterman&                 smithWaterman_;

};  // class AlignmentGenerator

}  // namespace align
}  // namespace dragenos

#endif  // #ifndef ALIGN_ALIGNMENT_GENERATOR_HPP