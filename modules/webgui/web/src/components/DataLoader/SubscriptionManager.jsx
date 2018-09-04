import React from 'react';
import { connect } from 'react-redux';
import DataManager from '../../api/DataManager';
import { setSelectedFilePaths, setVolumesConvertedCount, setVolumesToConvertCount } from '../../api/Actions/dataLoaderActions';
import { stringListToArray } from './utils/helpers';

class SubscriptionManager extends React.Component {
    constructor(props) {
		super(props);
		
		this.handleSelectedFiles = this.handleSelectedFiles.bind(this);
		this.subscribeToFilepaths = this.subscribeToFilepaths.bind(this);
		this.handleVolumesConvertedCount = this.handleVolumesConvertedCount.bind(this);
		this.handleVolumesToConvertCount = this.handleVolumesToConvertCount.bind(this);
	}

    componentDidMount() {
        this.subscribeToFilepaths();
    }

    componendWillUnmount() {
        console.log('unmounting subscription man.')
    }

	subscribeToFilepaths() {
        DataManager.subscribe('Modules.DataLoader.Loader.SelectedFiles', this.handleSelectedFiles);
        DataManager.subscribe('Modules.DataLoader.Loader.CurrentVolumesConvertedCount', this.handleVolumesConvertedCount);
        DataManager.subscribe('Modules.DataLoader.Loader.CurrentVolumesToConvertCount', this.handleVolumesToConvertCount);
    }

	handleSelectedFiles(data) {
        console.log('got files', data);
        this.props.setSelectedFilePaths(stringListToArray(data.Value));
    }

	handleVolumesConvertedCount(data) {
        this.props.setVolumesConvertedCount(Number(data.Value));
    }

	handleVolumesToConvertCount(data) {
        this.props.setVolumesToConvertCount(Number(data.Value));
    }
	
	render() {
        return null;
	}
}

const mapDispatchToProps = dispatch => ({
  setSelectedFilePaths: (filePaths) => {
    dispatch(setSelectedFilePaths(filePaths))
  },
  setVolumesConvertedCount: (count) => {
    dispatch(setVolumesConvertedCount(count))
  },
  setVolumesToConvertCount: (count) => {
    dispatch(setVolumesToConvertCount(count))
  }
});

SubscriptionManager = connect(
  null,
  mapDispatchToProps
)(SubscriptionManager);

export default SubscriptionManager;